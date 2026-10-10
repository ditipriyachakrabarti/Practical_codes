#include <iostream>
#include <fstream>
#include <string>
class Advisory {
public:
    virtual void giveAdvice() = 0;
    virtual ~Advisory() {}
};
class Crop {
protected:
    string name, season;
    double area, yieldPerAcre;
    static int count;
public:
    Crop(string n, double a, string s, double y) {
        if (a <= 0 || y <= 0)
            throw "Area and yield must be positive!";
        name = n;
        area = a;
        season = s;
        yieldPerAcre = y;
        count++;
    }
    Crop(string n, double a, double y)
        : Crop(n, a, "Not specified", y) {}
    virtual ~Crop() { count--; }
    virtual double totalYield() {
        return area * yieldPerAcre;
    }
    virtual void display() {
        cout << "\nCrop: " << name
             << "\nArea: " << area << " acres"
             << "\nSeason: " << season
             << "\nYield per acre: " << yieldPerAcre
             << " tonnes"
             << "\nTotal yield: " << totalYield()
             << " tonnes\n";
    }
    bool operator>(Crop& c) {
        return totalYield() > c.totalYield();
    }
    static int getCount() {
        return count;
    }
    virtual void save(ofstream& file) {
        file << name << " " << area << " "
             << season << " " << yieldPerAcre
             << " " << totalYield() << endl;
    }
    string getName() { return name; }
};
int Crop::count = 0;
class CerealCrop : public Crop, public Advisory {
    string fertilizer;
    int irrigation;
public:
    CerealCrop(string n, double a, string s, double y,
               string f, int i)
        : Crop(n, a, s, y) {
        if (i <= 0)
            throw "Irrigation must be positive!";
        fertilizer = f;
        irrigation = i;
    }
    CerealCrop(string n, double a, double y, string f, int i)
        : CerealCrop(n, a, "Not specified", y, f, i) {}
    double totalYield() override {
        return area * yieldPerAcre;
    }
    void display() override {
        cout << "\n--- CEREAL CROP ---";
        Crop::display();
        cout << "Fertilizer: " << fertilizer
             << "\nIrrigation per week: " << irrigation << endl;
    }
    void giveAdvice() override {
        cout << "Advice: Monitor weeds and irrigate as needed.\n";
    }
    void save(ofstream& file) override {
        Crop::save(file);
    }
};
class VegetableCrop : public Crop, public Advisory {
    string fertilizer;
    int irrigation;
public:
    VegetableCrop(string n, double a, string s, double y,
                  string f, int i)
        : Crop(n, a, s, y) {
        if (i <= 0)
            throw "Irrigation must be positive!";
        fertilizer = f;
        irrigation = i;
    }
    VegetableCrop(string n, double a, double y, string f, int i)
        : VegetableCrop(n, a, "Not specified", y, f, i) {}
    double totalYield() override {
        return area * yieldPerAcre;
    }
    void display() override {
        cout << "\n--- VEGETABLE CROP ---";
        Crop::display();
        cout << "Fertilizer: " << fertilizer
             << "\nIrrigation per week: " << irrigation << endl;
    }
    void giveAdvice() override {
        cout << "Advice: Maintain soil moisture and check for pests.\n";
    }
    void save(ofstream& file) override {
        Crop::save(file);
    }
};
int main() {
    try {
        cout << fixed << setprecision(2);

        CerealCrop c("Wheat", 5, "Rabi", 3.5, "Urea", 2);
        VegetableCrop v("Cauliflower", 2, "Winter", 8, "Organic", 4);
        Crop* crops[2] = {&c, &v};
        cout << "SMART FARM MANAGEMENT SYSTEM\n";
        for (int i = 0; i < 2; i++) {
            crops[i]->display();
        }
        Advisory* a[2] = {&c, &v};

        cout << "\n--- FARMING ADVICE ---\n";
        for (int i = 0; i < 2; i++) {
            a[i]->giveAdvice();
        }
        cout << "\n--- CROP COMPARISON ---\n";
        if (c > v)
            cout << c.getName() << " has higher total yield.\n";
        else if (v > c)
            cout << v.getName() << " has higher total yield.\n";
        else
            cout << "Both crops have equal total yield.\n";
        ofstream fout("crops.txt");
        if (!fout)
            throw "Unable to open file!";
        for (int i = 0; i < 2; i++)
            crops[i]->save(fout);
        fout.close();
        cout << "\nCrop data saved successfully.\n";
        ifstream fin("crops.txt");
        if (!fin)
            throw "Unable to read file!";
        cout << "\n--- SAVED CROP DATA ---\n";
        string line;
        while (getline(fin, line))
            cout << line << endl;
        fin.close();
        cout << "\nTotal crop objects: "
             << Crop::getCount() << endl;
    }
    catch (const char* error) {
        cout << "\nError: " << error << endl;
    }
    return 0;
}