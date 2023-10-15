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

        void Model(const string & filename)
        {
            for (int i = 0; i < 1; i++) {
                AddNewModel("Axis", "P7214", "5.50.2");
            }
            write_xml(filename, tree);
        }


        void AddNewCredentialsRef(const string& credentialsRef1) {
            pt::ptree credentialsRef;
            credentialsRef.add("<xmlattr>.id", credentialsRef1);
            tree.add_child("device.credentialsRef", credentialsRef);
        }

        void CredentialsRef(const string& filename)
        {
            for (int i = 0; i < 1; i++) {
                AddNewCredentialsRef("creds");
            }
            write_xml(filename, tree);
        }

        void AddNewVideoSourceRef(const string& videoSourceRef1, const string& videoStreamingRef, const string& detectorRef, const string& detectorRef1, const string& detectorRef2, const string& maxCount){
            pt::ptree videoSourceRef;
            videoSourceRef.add("<xmlattr>.id", videoSourceRef1);
            videoSourceRef.add("videoStreamingRef.<xmlattr>.id", videoStreamingRef);
            videoSourceRef.add("videoStreamingRef.<xmlattr>.maxCount", maxCount);
            videoSourceRef.add("detectorRef.<xmlattr>.id", detectorRef);
            videoSourceRef.add("detectorRef.<xmlattr>.maxCount", maxCount);
            videoSourceRef.add("detectorRef1.<xmlattr>.id", detectorRef1);
            videoSourceRef.add("detectorRef1.<xmlattr>.maxCount", maxCount);
            videoSourceRef.add("detectorRef2.<xmlattr>.id", detectorRef2);
            videoSourceRef.add("detectorRef2.<xmlattr>.maxCount", maxCount);
            tree.add_child("device.videoSourceRef", videoSourceRef);

        }
        void VideoSourceRef(const string& filename)
        {
            for (int i = 0; i < 2; i++) {
                AddNewVideoSourceRef("video_source_for_P7214", "vs_P712", "motion_detection","tampering_detection","audio_detection","1");
            }
            write_xml(filename, tree);
        }

        void AddNewTelemetryRef(const string& telemetryRef1) {
            pt::ptree telemetryRef;
            telemetryRef.add("<xmlattr>.id", telemetryRef1);
            tree.add_child("device.telemetryRef", telemetryRef);
        }

        void TelemetryRef(const string& filename)
        {
            for (int i = 0; i < 4; i++) {
                AddNewTelemetryRef("telemetry_P7214");
            }
            write_xml(filename, tree);
        }


        void AddNewAudioSourceRef(const string& audioSourceRef1) {
            pt::ptree audioSourceRef;
            audioSourceRef.add("<xmlattr>.id", audioSourceRef1);
            tree.add_child("device.audioSourceRef", audioSourceRef);
        }

        void AudioSourceRef(const string& filename)
        {
            for (int i = 0; i < 2; i++) {
                AddNewAudioSourceRef("as_g711_g726_aac_8-64_positive_gain");
            }
            write_xml(filename, tree);
        }


        void AddNewAudioDestinationRef(const string& audioDestinationRef1) {
            pt::ptree audioDestinationRef;
            audioDestinationRef.add("<xmlattr>.id", audioDestinationRef1);
            tree.add_child("device.audioDestinationRef", audioDestinationRef);
        }

        void AudioDestinationRef(const string& filename)
        {
            for (int i = 0; i < 1; i++) {
                AddNewAudioDestinationRef("ad_g711_g726_output_gain_9_53");
            }
            write_xml(filename, tree);
        }

        void AddNewSerialPortRef(const string& serialPortRef1) {
            pt::ptree serialPortRef;
            serialPortRef.add("<xmlattr>.id", serialPortRef1);
            tree.add_child("device.serialPortRef", serialPortRef);
        }

        void SerialPortRef(const string& filename)
        {
            for (int i = 0; i < 1; i++) {
                AddNewSerialPortRef("serial_axis_P72");
            }
            write_xml(filename, tree);
        }

        void AddNewIoDeviceRef(const string& ioDeviceRef1) {
            pt::ptree ioDeviceRef;
            ioDeviceRef.add("<xmlattr>.id", ioDeviceRef1);
            tree.add_child("device.ioDeviceRef", ioDeviceRef);
        }

        void IoDeviceRef(const string& filename)
        {
            for (int i = 0; i < 1; i++) {
                AddNewIoDeviceRef("iodev_4x4_configurable");
            }
            write_xml(filename, tree);
        }
        //write_xml("debug_settings_out.xml", tree);
};

//массив моделей отдельные элементы множества.


int main()
{
    XMLElement element; // объявление объекта
    element.Model("debug_settings_out.xml");
    element.CredentialsRef("debug_settings_out.xml");
    element.VideoSourceRef("debug_settings_out.xml");
    element.TelemetryRef("debug_settings_out.xml");
    element.AudioSourceRef("debug_settings_out.xml");
    element.AudioDestinationRef("debug_settings_out.xml");
    element.SerialPortRef("debug_settings_out.xml");
    element.IoDeviceRef("debug_settings_out.xml");
    return 0;
}