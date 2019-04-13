class Product
{
protected:
    unsigned char state;
    int pId;
public:
    Product(int pId) { this->pId = pId; state = 0; };
    ~Product();
    int getPID() { return pId; }
};
