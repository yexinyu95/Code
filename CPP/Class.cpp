#include <iostream>


struct salesData
{
//  members of the struct, similar to C,
    std::string bookNo;
    unsigned unitsSold = 0;
    double revenue = 0.0;

//  operations declared inside the struct, but may not defined inside the struct,
    std::string isbn() const{return bookNo;}
    double avgPrice() const;
    salesData& combine(const salesData&);
};

// functions defined outside the struct, scope operator:: is required,
double salesData::avgPrice(void) const
{
    if  (unitsSold)
        {return revenue / unitsSold;}
    else 
        {return 0;}
}

salesData& salesData::combine(const salesData& rethis)
{
    unitsSold += rethis.unitsSold;
    revenue   += rethis.revenue;

    return *this;
}

/*  methods that not members of the Class,
    they use the Class' instances 
    instead of using the member of Class directly,
*/
salesData add(const salesData&);
std::ostream& print(std::ostream&, const salesData&);
std::istream& read (std::istream&, salesData&);

std::istream &read (std::istream &is, salesData &item)
{
    double price = 0;
    is >> item.bookNo >> item.unitsSold >> price;
    item.revenue = price * item.unitsSold;

    return is;
}

std::ostream &print (std::ostream &os, const salesData &item)
{
    os << item.isbn()  << " " << item.unitsSold << " "
       << item.revenue << " " << item.avgPrice();

    return os;
}

salesData add (const salesData& lhs, salesData& rhs)
{
    salesData sum = lhs;
    sum.combine(rhs);

    return sum;
}



int main ()
{
    salesData total;
    total.bookNo = "CPP";

    std::cout << __cplusplus << std::endl;

    std::cin.get();
    
    return 0;
}