#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/detail/file_parser_error.hpp>
#include <string>
#include <fstream>

using namespace std;
namespace my_tree = boost::property_tree;


int main(int argc, char* argv[])
{
    my_tree::ptree pt;
    boost::property_tree::ptree device;
    boost::property_tree::ptree model;
    boost::property_tree::ptree credentialsRef;
    boost::property_tree::ptree videoSourceRef1;
    boost::property_tree::ptree videoStreamingRef1;
    boost::property_tree::ptree detectorRef11;
    boost::property_tree::ptree detectorRef12;
    boost::property_tree::ptree detectorRef13;
    boost::property_tree::ptree videoStreamingRef;
    boost::property_tree::ptree detectorRef1;
    boost::property_tree::ptree detectorRef2;
    boost::property_tree::ptree videoSourceRef;
    boost::property_tree::ptree telemetryRef;
    boost::property_tree::ptree audioSourceRef;
    boost::property_tree::ptree audioDestinationRef;
    boost::property_tree::ptree serialPortRef;
    boost::property_tree::ptree ioDeviceRef;


    model.put("brand", "Axis");
    model.put("name", "P7214");
    model.put("firmware", "5.50.2");
    device.add_child("model", model);

    credentialsRef.put("<xmlattr>.id", "creds");
    device.add_child("credentialsRef", credentialsRef);

    
    for (int i = 0; i < 1; i++) {
        videoStreamingRef1.add("<xmlattr>.id", "vs_P712");
        videoStreamingRef1.put("<xmlattr>.default", "true");
        detectorRef11.add("<xmlattr>.id", "motion_detection");
        detectorRef11.put("<xmlattr>.maxCount", "1");
        detectorRef12.add("<xmlattr>.id", "tampering_detection");
        detectorRef12.put("<xmlattr>.maxCount", "1");
        detectorRef13.add("<xmlattr>.id", "audio_detection");
        detectorRef13.put("<xmlattr>.maxCount", "1");

        videoSourceRef1.add_child("videoStreamingRef", videoStreamingRef1);
        videoSourceRef1.add_child("detectorRef", detectorRef11);
        videoSourceRef1.add_child("detectorRef", detectorRef12);
        videoSourceRef1.add_child("detectorRef", detectorRef13);
    }
    videoSourceRef1.put("<xmlattr>.id", "video_source_for_P7214");
    device.add_child("videoSourceRef", videoSourceRef1);


    for (int i = 0; i < 1; i++) {
        videoStreamingRef.add("<xmlattr>.id", "vs_P712");
        videoStreamingRef.put("<xmlattr>.default", "true");
        detectorRef1.add("<xmlattr>.id", "motion_detection");
        detectorRef1.put("<xmlattr>.maxCount", "1");
        detectorRef2.add("<xmlattr>.id", "tampering_detection");
        detectorRef2.put("<xmlattr>.maxCount", "1");

        videoSourceRef.add_child("videoStreamingRef", videoStreamingRef);
        videoSourceRef.add_child("detectorRef", detectorRef1);
        videoSourceRef.add_child("detectorRef", detectorRef2);
    }
    videoSourceRef.put("<xmlattr>.id", "video_source_for_P7214");
    device.add_child("videoSourceRef", videoSourceRef);

    
    for (int i = 0; i < 4; i++) {
        telemetryRef.put("<xmlattr>.id", "telemetry_P7214");
        device.add_child("telemetryRef", telemetryRef);
    }


    for (int i = 0; i < 2; i++) {
        audioSourceRef.put("<xmlattr>.id", "as_g711_g726_aac_8-64_positive_gain");
        device.add_child("audioSourceRef", audioSourceRef);
    }

    audioDestinationRef.put("<xmlattr>.id", "ad_g711_g726_output_gain_9_53");
    device.add_child("audioDestinationRef", audioDestinationRef);

    serialPortRef.put("<xmlattr>.id", "serial_axis_P72");
    device.add_child("serialPortRef", serialPortRef);


    ioDeviceRef.put("<xmlattr>.id", "iodev_4x4_configurable");
    device.add_child("ioDeviceRef", ioDeviceRef);

    pt.add_child("device", device);
    write_xml("myfile.xml", pt);

    return 0;
}
