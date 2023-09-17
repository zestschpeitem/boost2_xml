#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/detail/file_parser_error.hpp>
#include <string>

using namespace std;
namespace pt = boost::property_tree;

class ModelXMLElement {
public:
    string element1;
    string element2;
    string element3;
        ;
    ModelXMLElement() = default;
    ModelXMLElement(string id1, string id2, string id3) : element1(id1), element2(id2), element3(id3) {

    }
};

int main(int argc, char* argv[])
{
    pt::ptree mychild;
    pt::ptree mypt;
    ModelXMLElement* myobj[1] = { new ModelXMLElement("Axis","P7214","5.50.2")};
    for (int i = 0; i < 1; i++) {
        mychild.add("brand", myobj[i]->element1);
        mychild.add("name", myobj[i]->element2);
        mychild.add("firmware", myobj[i]->element3);
        mypt.add_child("device.model", mychild);
        mychild.clear();
    }

    write_xml("myfile.xml", mypt);

    return 0;
}
