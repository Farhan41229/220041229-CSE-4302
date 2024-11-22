#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int randomnumber(int lower_bound, int upper_bound){
    // std::srand(static_cast<unsigned>(std::time(0)));
    return (std::rand() % (upper_bound - lower_bound + 1)) + lower_bound;
}

class SellerActions {
public:
    virtual void serveIceCream() = 0;
    virtual void promoteDeal() = 0;
    virtual void specialOffer() = 0;
    virtual void displayStats() const = 0;
    virtual ~SellerActions() = default;
};

// Base class for sellers
class BaseSeller : public SellerActions {
protected:
    string name;
    int stock;
    int sales;
    bool specialOfferReady;
    
public:
    static int collectiveSales;
    BaseSeller(const string& sellerName, int initialStock)
        : name(sellerName), stock(initialStock), sales(0), specialOfferReady(false) {}

    string getName() const { return name; }
    void getCollectiveSales() const { cout<<"Collective sales: "<<collectiveSales<<endl; }
    int getCollectiveSales2() const { return collectiveSales; }
    // virtual void LayeredSundaeBonus(int layers) {}
    // virtual void ConeStackChallenge(int scoopsStacked) {}

    void serveIceCream() {
        if (stock > 0) {
            int saleIncrease = randomnumber(8, 30); 
            stock--;
            sales += saleIncrease;
            collectiveSales += sales;
            if (sales % 3 == 0) {
                specialOfferReady = true;
            }
            cout << name << " served! Sales increased by " << saleIncrease
                 << ". Total Sales: " << sales << ", Stock: " << stock << endl;
        } else {
            cout << name << " is out of stock!" << endl;
        }
    }

    void promoteDeal() {
        // Temporary boost logic can be added here
        cout << name << " PROMOTE DEAL CALLED!!!" << endl;
    }

    void displayStats() const {
        cout << "Name: " << name << ", Stock: " << stock
             << ", Sales: " << sales
             << ", Special Offer Ready: " << (specialOfferReady ? "Yes" : "No") << endl;
    }
};

int BaseSeller:: collectiveSales = 0;

// ConeMaster class
class ConeMaster : public BaseSeller {
public:
    ConeMaster() : BaseSeller("Cone Master", 20) {}

    void specialOffer() {
        if (specialOfferReady) {
            int TotalIncrease = 0;
            for (int i = 0; i < 3 && stock > 0; ++i) {
                int saleIncrease = randomnumber(8, 30);
                stock--;
                TotalIncrease += saleIncrease;
            }
            sales += TotalIncrease;
            collectiveSales += sales;
            specialOfferReady = false;
            cout << name << " served a specialOffer! Sales increased by " << TotalIncrease
                 << ". Total Sales: " << sales << ", Stock: " << stock << endl;
        } else {
            cout << name << "'s special offer is not ready!" << endl;
        }
    }

    void ConeStackChallenge(int scoopsStacked) {
        int successRate = 100 - (scoopsStacked * 10);
        int randomChance = randomnumber(1, 100);

        if (randomChance <= successRate && stock > 0) {
            int saleIncrease = scoopsStacked * randomnumber(8, 30);
            stock--;
            sales += saleIncrease;
            collectiveSales += sales;
            cout << name << " succeeded in ConeStackChallenge! Sales increased by " << saleIncrease
                 << ". Total Sales: " << sales << ", Stock: " << stock << endl;
        } else {
            if (stock > 0) {
                stock--; // Stock is wasted if the challenge fails
                cout << name << " failed ConeStackChallenge! Stock wasted. Stock: " << stock << endl;
            } else {
                cout << name << " has no stock for ConeStackChallenge!" << endl;
            }
        }
    }
};

// SundaeWizard class
class SundaeWizard : public BaseSeller {
public:
    SundaeWizard() : BaseSeller("Sundae Wizard", 15) {}

    void specialOffer() {
        if (1) {
            int salesBoost = sales;
            sales += salesBoost;
            collectiveSales += sales;
            specialOfferReady = false;
            cout << name << " served a specialOffer! Sales increased by " << salesBoost
                 << ". Total Sales: " << sales << ", Stock: " << stock << endl;
        } else {
            cout << name << "'s special offer is not ready!" << endl;
        }
    }

    void LayeredSundaeBonus(int layers) {
        
            int bonus = layers * randomnumber(8, 30);
            stock--;
            sales += bonus;
            collectiveSales += sales;
            cout << name << " served LayeredSundaeBonus! Sales increased by " << bonus
                 << ". Total Sales: " << sales << ", Stock: " << stock << endl;
        
    }
};

// IceCreamTruckDriver class
class IceCreamTruckDriver : public BaseSeller {
public:
    IceCreamTruckDriver() : BaseSeller("Ice Cream Truck Driver", 30) {}

    void specialOffer() override {
        if (1) {
            stock += 10;
            specialOfferReady = false;
            cout << name << " used a specialOffer! Restocked 10 units. Stock: " << stock << endl;
        } else {
            cout << name << "'s special offer is not ready!" << endl;
        }
    }
};

// Simulation engine class
class SimulationEngine {
private:
    vector<BaseSeller*> sellers;
    int customerPatience;
    int breakcondition = 30000;

public:
    SimulationEngine() : customerPatience(200) {}

    void addSeller(BaseSeller* seller) {
        sellers.push_back(seller);
    }

    void simulate() {
    int turn = 1;

    while (customerPatience > 0) {
        cout << "Turn " << turn << ":\n";
        for (auto& seller : sellers) {
            if (BaseSeller::collectiveSales >= breakcondition) break;

            if (turn % 3 ==0 && seller->getName() == "Sundae Wizard"){
                dynamic_cast<SundaeWizard*>(seller)->LayeredSundaeBonus(turn);
            }
            if (turn % 3 ==0 && seller->getName() == "Cone Master"){
                dynamic_cast<ConeMaster*>(seller)->ConeStackChallenge(turn);
            }

            else if (turn % 4 == 0) {
                seller->specialOffer();
            } 
            else {
                seller->serveIceCream();
            }

            seller->getCollectiveSales();
        }

        // Check total sales after each turn
        if (BaseSeller::collectiveSales >= breakcondition) {
            break;
        }

        customerPatience -= randomnumber(20, 50); // Decrease patience by 20-50 points
        cout << "Customer patience: " << customerPatience << endl;

        turn++;
    }

    if (BaseSeller::collectiveSales >= breakcondition) {
        cout << "Customer Rush satisfied! Sellers win!" << endl;
    } else {
        cout << "Customer Rush not satisfied! Sellers lose!" << endl;
    }
}

};

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    SimulationEngine engine;
    ConeMaster coneMaster;
    SundaeWizard sundaeWizard;
    IceCreamTruckDriver truckDriver;

    engine.addSeller(&coneMaster);
    engine.addSeller(&sundaeWizard);
    engine.addSeller(&truckDriver);

    engine.simulate();

}