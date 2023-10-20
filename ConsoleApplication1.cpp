#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <string>
#include <iostream>

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

        pt::ptree detectorRef;
        void AddNewDetectorRef(const string& id, const string& maxCount) {
            pt::ptree detectorRef;
            detectorRef.add("<xmlattr>.id", id);
            detectorRef.add("<xmlattr>.maxCount", maxCount);
        }

        void AddNewVideoSourceRef(const string& videoSourceRef1, const string& videoStreamingRef, const string& default1) {
            pt::ptree videoSourceRef;
            videoSourceRef.add("<xmlattr>.id", videoSourceRef1);
            videoSourceRef.add("videoStreamingRef.<xmlattr>.id", videoStreamingRef);
            videoSourceRef.add("videoStreamingRef.<xmlattr>.default", default1);
            videoSourceRef.add_child("detectorRef", detectorRef);
            tree.add_child("device.videoSourceRef", videoSourceRef);
            
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

    element.AddNewModel("Axis", "P7214", "5.50.2");

    element.AddNewCredentialsRef("creds");

    element.AddNewVideoSourceRef( "video_source_for_P7214", "vs_P712", "true");

    element.AddNewDetectorRef("motion_detection", "1");

    element.AddNewVideoSourceRef("video_source_for_P7214", "vs_P712", "true");

    element.AddNewDetectorRef("motion_detection", "1");

    element.WriteXML("debug_settings_out.xml");

    return 0;
}