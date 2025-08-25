#include <iostream>
#include <map>
#include <vector>


enum class ComponentType{TEXTURE, COLLISION, POSITION};


// interface
struct IComponent{
    virtual void Update() = 0;
    virtual ComponentType GetType() = 0;

};

struct TextureComponent : public IComponent{

    void Update() {
        std::cout << "Update Texture " << std::endl;
    }

    ComponentType GetType(){
        return ComponentType::TEXTURE;
    }
};

struct CollisionComponent : public IComponent{

    void Update() {
        std::cout << "Update Collison " << std::endl;
    }

    ComponentType GetType(){
        return ComponentType::COLLISION;
    }
};

struct PositionComponent : public IComponent{

    void Update() {
        std::cout << "Update Position " << std::endl;
    }

    ComponentType GetType(){
        return ComponentType::POSITION;
    }
};


struct GameObject {

    void Update() {

        for (const auto& [key, value] : components) //call update for each component
        {
            components[key]->Update();  
        }
    }

    //adding component into map
    void AddComponent (IComponent* comp) {
        components[comp->GetType()] = comp;
    }


    IComponent* GetComponent(ComponentType type){
        auto foundComponent = components.find(type);

        if(foundComponent != components.end()){
            return foundComponent->second;
        }
        else{
            return nullptr;
        }
    }

    std::map<ComponentType, IComponent*> components; 
};



int main() {

    GameObject mario;
    TextureComponent texture;
    PositionComponent pos;
    CollisionComponent col;

    mario.AddComponent(&texture);
    mario.AddComponent(&pos);
    mario.AddComponent(&col);


    auto retrieve  = mario.GetComponent(ComponentType::TEXTURE);
    retrieve->Update();

    mario.Update();


    return 0;
}