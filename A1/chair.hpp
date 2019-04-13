#define NORMAL_CHAIR      0x1F
#define NOBACKREST_CHAIR  0x1B
#define ARMREST_CHAIR     0X0F

class Chair {
    unsigned char state;
    int pId;
public:
    Chair(int productId) { state = 0; pId = productId; }
    Chair(int productId, unsigned char state) { this->state = state; pId = productId; };

    bool C(void) { return state & 0x01; }
    bool F(void) { return state & 0x02; }
    bool B(void) { return state & 0x04; }
    bool S(void) { return state & 0x08; }
    bool P(void) { return state & 0x10; }
    bool A(void) { return state & 0x20; }

    void Cdone(void) { state |= 0x01; }
    void Fdone(void) { state |= 0x02; }
    void Bdone(void) { state |= 0x04; }
    void Sdone(void) { state |= 0x08; }
    void Pdone(void) { state |= 0x10; }
    void Adone(void) { state |= 0x20; }

    bool isDone(const unsigned char chairType) { return state == chairType; }

    int getPID(void) { return pId; }
};

