#include <iostream>

class Stonewt
{
    private:
    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
    public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    operator int() const;
    operator double() const;
};

using std::cout;

Stonewt::Stonewt(double lbs)
{
    stone = int (lbs);
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()
{
}

void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

Stonewt::operator int() const
{
    return int (pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds;
}

int main()
{
    Stonewt poppins(9, 2.8);
    double p_wt = poppins;
    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int (poppins) << " pounds.\n";
    return 0; 
}