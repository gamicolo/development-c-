void error(char s)
{
    //do something
    std::cout<<"calling error"<<std::endl;
};

void (*efct)(char);   //pointer to a function

void f()
{
    efct = &error;      //efcf points to error
    efct('a');          //call error through efct
};

int main()
{
    f();
}
