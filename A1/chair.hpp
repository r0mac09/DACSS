#define NORMAL_CHAIR      0x1F
#define NOBACKREST_CHAIR  0x1B
#define ARMREST_CHAIR     0X0F

class Chair {
public:
    Chair(int productId) { state = 0; pId = productId; }
    Chair(int productId, unsigned char state) { this->state = state; pId = productId; };

    // The following functions tell if a specific task has been done to the chair
    bool Cdone(Chair* chair) { return chair->state & 0x01; }
    bool Fdone(Chair* chair) { return chair->state & 0x02; }
    bool Bdone(Chair* chair) { return chair->state & 0x04; }
    bool Sdone(Chair* chair) { return chair->state & 0x08; }
    bool Pdone(Chair* chair) { return chair->state & 0x10; }
    bool Adone(Chair* chair) { return chair->state & 0x20; }

    // The following functions do a specific task to the chair
    void C(Chair* chair) { chair->state |= 0x01; }
    void F(Chair* chair) { chair->state |= 0x02; }
    void B(Chair* chair) { chair->state |= 0x04; }
    void S(Chair* chair) { chair->state |= 0x08; }
    void P(Chair* chair) { chair->state |= 0x10; }
    void A(Chair* chair) { chair->state |= 0x20; }

    // Returns wether a chair completion state matches a specific chair type
    bool isDone(const unsigned char chairType) { return state == chairType; }

    // Returns the product id to be used somewhere else but not modified
    int getPID(Chair* chair) { return chair->pId; }

    // Represents the state of the chair from which
    // can be determined the work that it has been done to it
    unsigned char state;

    // Product id to identify easily a specific chair
    int pId;
};

