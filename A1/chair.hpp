#define NORMAL_CHAIR      0x1F
#define NOBACKREST_CHAIR  0x1B
#define ARMREST_CHAIR     0X0F

class Chair {
    // Represents the state of the chair from which
    // can be determined the work that it has been done to it
    unsigned char state;

    // Product id to identify easily a specific chair
    int pId;
public:
    Chair(int productId) { state = 0; pId = productId; }
    Chair(int productId, unsigned char state) { this->state = state; pId = productId; };

    // The following functions tell if a specific task has been done to the chair
    bool Cdone(void) { return state & 0x01; }
    bool Fdone(void) { return state & 0x02; }
    bool Bdone(void) { return state & 0x04; }
    bool Sdone(void) { return state & 0x08; }
    bool Pdone(void) { return state & 0x10; }
    bool Adone(void) { return state & 0x20; }

    // The following functions do a specific task to the chair
    void C(void) { state |= 0x01; }
    void F(void) { state |= 0x02; }
    void B(void) { state |= 0x04; }
    void S(void) { state |= 0x08; }
    void P(void) { state |= 0x10; }
    void A(void) { state |= 0x20; }

    // Returns wether a chair completion state matches a specific chair type
    bool isDone(const unsigned char chairType) { return state == chairType; }

    // Returns the product id to be used somewhere else but not modified
    int getPID(void) { return pId; }
};

