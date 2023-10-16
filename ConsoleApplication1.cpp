#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <string>
#include <exception>
#include <iostream>
#include <set>

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

        void Model()
        {
            AddNewModel("Axis", "P7214", "5.50.2");
        }


        void AddNewCredentialsRef(const string& credentialsRef1) {
            pt::ptree credentialsRef;
            credentialsRef.add("<xmlattr>.id", credentialsRef1);
            tree.add_child("device.credentialsRef", credentialsRef);
        }

        void CredentialsRef()
        {
            AddNewCredentialsRef("creds");
        }

        void AddNewVideoSourceRef(const string& videoSourceRef1, const string& videoStreamingRef, const string& default1, const string& id, const string& id1, const string& id2, const string& maxCount){
            pt::ptree videoSourceRef;
            struct { string id, maxCount; } data[] = {
        { id, maxCount },
        { id1, maxCount },
        { id2, maxCount },
            };
            videoSourceRef.add("<xmlattr>.id", videoSourceRef1);
            videoSourceRef.add("videoStreamingRef.<xmlattr>.id", videoStreamingRef);
            videoSourceRef.add("videoStreamingRef.<xmlattr>.default", default1);

            for (auto& item : data) {
                pt::ptree detectorRef;
                detectorRef.add("<xmlattr>.id", item.id);
                detectorRef.add("<xmlattr>.maxCount", item.maxCount);
                videoSourceRef.add_child("detectorRef", detectorRef);
            };
            videoSourceRef.erase(id2);
            tree.add_child("device.videoSourceRef", videoSourceRef);

        }


        void VideoSourceRef()
        {
            AddNewVideoSourceRef("video_source_for_P7214", "vs_P712", "true", "motion_detection","tampering_detection","audio_detection","1");
        }


        void AddNewTelemetryRef(const string& telemetryRef1) {
            pt::ptree telemetryRef;
            telemetryRef.add("<xmlattr>.id", telemetryRef1);
            tree.add_child("device.telemetryRef", telemetryRef);
        }

        void TelemetryRef()
        {
            AddNewTelemetryRef("telemetry_P7214");
        }


        void AddNewAudioSourceRef(const string& audioSourceRef1) {
            pt::ptree audioSourceRef;
            audioSourceRef.add("<xmlattr>.id", audioSourceRef1);
            tree.add_child("device.audioSourceRef", audioSourceRef);
        }

        void AudioSourceRef()
        {
            AddNewAudioSourceRef("as_g711_g726_aac_8-64_positive_gain");
        }


        void AddNewAudioDestinationRef(const string& audioDestinationRef1) {
            pt::ptree audioDestinationRef;
            audioDestinationRef.add("<xmlattr>.id", audioDestinationRef1);
            tree.add_child("device.audioDestinationRef", audioDestinationRef);
        }

        void AudioDestinationRef()
        {
            AddNewAudioDestinationRef("ad_g711_g726_output_gain_9_53");
        }

        void AddNewSerialPortRef(const string& serialPortRef1) {
            pt::ptree serialPortRef;
            serialPortRef.add("<xmlattr>.id", serialPortRef1);
            tree.add_child("device.serialPortRef", serialPortRef);
        }

        void SerialPortRef()
        {
            AddNewSerialPortRef("serial_axis_P72");
        }

        void AddNewIoDeviceRef(const string& ioDeviceRef1) {
            pt::ptree ioDeviceRef;
            ioDeviceRef.add("<xmlattr>.id", ioDeviceRef1);
            tree.add_child("device.ioDeviceRef", ioDeviceRef);
        }

        void IoDeviceRef()
        {
            AddNewIoDeviceRef("iodev_4x4_configurable");
        }

        void WriteXML(const string& filename){
            Model();
            CredentialsRef();
            VideoSourceRef();
            TelemetryRef();
            AudioSourceRef();
            AudioDestinationRef();
            SerialPortRef();
            IoDeviceRef();
            write_xml(filename, tree);
        }
};

//массив моделей отдельные элементы множества.


int main()
{
    XMLElement element; // объявление объекта
    element.WriteXML("debug_settings_out.xml");
    return 0;
}