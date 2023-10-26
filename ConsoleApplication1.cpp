#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <string>
#include <iostream>
#include <list>
using namespace std;
namespace pt = boost::property_tree;

class XMLElement
{
    pt::ptree tree;

    public:
        void AddNewModel(const string& brand, const string& name, const string& firmware) {
            pt::ptree modeltree;
            modeltree.add("brand", brand);
            modeltree.add("name", name);
            modeltree.add("firmware", firmware);
            tree.add_child("device.model", modeltree);
        }

        void AddNewCredentialsRef(const string& credentialsRef1) {
            pt::ptree credentialsRef;
            credentialsRef.add("<xmlattr>.id", credentialsRef1);
            tree.add_child("device.credentialsRef", credentialsRef);
        }



        void AddNewVideoSourceRef(const string& videoSourceRef1, const string& videoStreamingRef, const string& default1) {
            pt::ptree videoSourceRef;
            videoSourceRef.add("<xmlattr>.id", videoSourceRef1);
            videoSourceRef.add("videoStreamingRef.<xmlattr>.id", videoStreamingRef);
            videoSourceRef.add("videoStreamingRef.<xmlattr>.default", default1);
            
            tree.add_child("device.videoSourceRef", videoSourceRef);
        }

        void AddNewDetectorRef(const string& videoSourceRef_id, const string& id, const string& maxCount) {
            pt::ptree detectorRef;
            detectorRef.add("<xmlattr>.id", id);
            detectorRef.add("<xmlattr>.maxCount", maxCount);
            pt::ptree::const_assoc_iterator it;
            it = tree.find("device");
            if (it != tree.not_found()) {
                auto& propset1 = tree.get_child("device");
                for (auto& propset2 : tree.get_child("device")) {
                    for (auto& p : propset2.second) {
                        for (auto& c : p.second) {
                            if (c.second.data() == videoSourceRef_id) {
                                auto& propset3 = propset2.get_child(propset2.first.data());
                                propset3.add_child("detectorRef", detectorRef);
                            }
                        }
                    }
                }
            }
        }


        void AddNewTelemetryRef(const string& telemetryRef1) {
            pt::ptree telemetryRef;
            telemetryRef.add("<xmlattr>.id", telemetryRef1);
            tree.add_child("device.telemetryRef", telemetryRef);
        }


        void AddNewAudioSourceRef(const string& audioSourceRef1) {
            pt::ptree audioSourceRef;
            audioSourceRef.add("<xmlattr>.id", audioSourceRef1);
            tree.add_child("device.audioSourceRef", audioSourceRef);
        }


        void AddNewAudioDestinationRef(const string& audioDestinationRef1) {
            pt::ptree audioDestinationRef;
            audioDestinationRef.add("<xmlattr>.id", audioDestinationRef1);
            tree.add_child("device.audioDestinationRef", audioDestinationRef);
        }


        void AddNewSerialPortRef(const string& serialPortRef1) {
            pt::ptree serialPortRef;
            serialPortRef.add("<xmlattr>.id", serialPortRef1);
            tree.add_child("device.serialPortRef", serialPortRef);
        }


        void AddNewIoDeviceRef(const string& ioDeviceRef1) {
            pt::ptree ioDeviceRef;
            ioDeviceRef.add("<xmlattr>.id", ioDeviceRef1);
            tree.add_child("device.ioDeviceRef", ioDeviceRef);
        }

        void WriteXML(const string& filename){
            write_xml(filename, tree);
        }
};



int main()
{
    XMLElement element; // объявление объекта

    element.AddNewVideoSourceRef( "video_source_for_P7214", "vs_P712", "true");
    

    element.AddNewVideoSourceRef("video_source_for_P72141111111", "vs_P712", "true");
    element.AddNewVideoSourceRef("video_source_for_P721411", "vs_P712", "true");
    element.AddNewVideoSourceRef("video_source_for_P721413333333", "vs_P712", "true");

    element.AddNewDetectorRef("video_source_for_P721411", "motion_detection", "1");
    element.AddNewDetectorRef("video_source_for_P72141111111", "motion_detection", "1");
    element.WriteXML("debug_settings_out.xml");



    return 0;
}