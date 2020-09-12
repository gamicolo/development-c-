#include <iostream>
#include <string>

class Entity
{
    public:
        std::string GetName() { return "Entity"; }
};

class Player : public Entity
{
    private:
        std::string m_Name;
    public:
        Player(const std::string& name) : m_Name(name) {}

        std::string GetName() {return m_Name;}

        void SetName( std::string& val)
        {
            m_Name = val;
            val = "modificando";
        }
};

int main()
{
    Entity* e = new Entity();
    std::cout << e->GetName() << std::endl;

    Player* p = new Player("PlayerGuiller");
    std::cout << p->GetName() << std::endl;

    std::string name_aux = "prueba";
    std::cout << "name_aux: " << name_aux << std::endl;
    p->SetName(name_aux);
    std::cout << p->GetName() << std::endl;
    std::cout << "name_aux: " << name_aux << std::endl;
}
