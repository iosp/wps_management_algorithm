#include <thread>
#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "managementalgorithm.h"

#ifdef CODE
#endif
class AlgorithmSubSystem;

ManagementAlgorithm::ManagementAlgorithm()
{
    //Create AlgorithmSubSystem
    m_alg_ptr = new AlgorithmSubSystem(this);
    //m_alg_ptr->setMngPointer(this);
    std::cout<<"AlgorithmSubSystem has been created!"<<std::endl;
    m_alg_ptr->InitiateSensorLocationReporting(10,10);
    m_thread_id=0;
}

ManagementAlgorithm::ManagementAlgorithm(const ManagementAlgorithm &old_obj)
{
     m_alg_ptr=old_obj.m_alg_ptr;
     m_thread_id=old_obj.m_thread_id;

}

int ManagementAlgorithm::Cons_InitiateSensorLocationReporting(Region_Of_Mission rom, int frequency)
{
    /***
     *  This method is called from the console or from another system.
     *  It iniated the sensor of location reporting.
     *  The inserted parameters are:
     *  Region of Mission for the sensor to report on
     *  Frequency in Hz of the report
     *  The return value is 0 for success and 1 for failure
     *  Observer pattern should be considered.
     * ***/

    int ret;
    //Call algorithm module
    std::cout<<"ManagementAlgorithm::Cons_InitiateSensorLocationReporting called with param:"<<rom<<std::endl;

    ret = m_alg_ptr->InitiateSensorLocationReporting(rom, frequency);
    return ret;
}

int ManagementAlgorithm::Cons_StopSensorLocationReporting()
{
    /*** This method is called by the console or any software module
     * no more interested by the value
     * of the sensor.
     * They will be deregister from the list of interested modules
     * and if noone is left that the algorithm module will be called
     * ***/
    int ret;
    //After removing observer, if no more left then call algorithm module
    std::cout<<"ManagementAlgorithm::Cons_StopSensorLocationReporting called "<<std::endl;
    ret = m_alg_ptr->StopSensorLocationReporting();
    return ret;

}

int ManagementAlgorithm::ProcessSensorLocUpdate(Calculated_Sensor_Geo_Loc_Orient geo_loc_orient)
{
    std::cout<<"ManagementAlgorithm::ProcessSensorLocUpdate called with param:"<<geo_loc_orient<<std::endl;
    //Here should be called the method update of the observers.
    // For example console.
    return 0;
}

int ManagementAlgorithm::UploadWPSData(Tile tile)
{
    //This method connects to the cloud and upload the tile
    std::cout<<"ManagementAlgorithm::UploadWPSData called with param:"<<tile<<std::endl;

    return 0;
}
int ManagementAlgorithm::Cons_PrepareForModelConstruction(Region_Of_Mission rom, int required_model_quality)
{
    /***
     * This method is generally called by the console in order to initiate a mission of building model.
     * Input parameters:
     * Region On Mission, required model quality
     * This method should place the state of this module in "Preparing" in one way and open a connection
     * to the cloud in order to get the corresponding orthophoto and WPS model.
     * ***/
    int ret;
    std::cout<<"ManagementAlgorithm::Cons_PrepareForModelConstruction called with param:"<<rom<<std::endl;
    char orthophoto[1024], wps_buff[1024];
    //Call algorithm module
    ret = m_alg_ptr->PrepareForModelConstruction(rom,required_model_quality, (char **)&orthophoto, (char **)&wps_buff);
    return ret;
}

int ManagementAlgorithm::Cons_StopModelConstruction()
{
    int ret;
    //Call algorithm module
    std::cout<<"ManagementAlgorithm::Cons_StopModelConstruction called "<<std::endl;

    ret = m_alg_ptr->StopModelConstruction();
    return ret;

}

void ManagementAlgorithm::readPlatformLocation()
{
    //open thread according aggreed frequency and get platform sensor values
    //Pseudo code
    int thread_id;
    Platform_Location_Info location_info=0;
    std::cout<<"ManagementAlgorithm::readPlatformLocation called "<<std::endl;

    thread_id=1001;
    m_thread_id = thread_id;
    m_alg_ptr->UpdateSensorLocOrient(location_info);

}

int ManagementAlgorithm::StopUdatingLocation()
{
    //close thread
    //Pseudo code
    std::cout<<"ManagementAlgorithm::StopUdatingLoc called "<<std::endl;

    m_thread_id = 0;
    return 0;
}

DateAndTime ManagementAlgorithm::QueryRoMLastDateAndTime(Region_Of_Mission rom)
{
    //This function is used to find out the last updated date & time of a specific ROM

    return 0;

}

void ManagementAlgorithm::ProcessNotification(AlgBuildingNotificationTypes alg_type)
{
    //This method is called by the algorithm module in order to report some
    std::cout<<"ManagementAlgorithm::ProcessNotification called with param:"<<alg_type<<std::endl;

    switch (alg_type)
    {
        case AlgModInit: break;
        case AlgModReadyForConstruction: //report console
                                        break;
        case AlgModBuilding: //report console
                                        break;
        case AlgModConstructionComplete: //Bravo!! Report to the console
                                        break;
        case AlgModConstructionStopped: //This is sent after StopSensorLocationReporting has been called
                                        break;
    default:
            std::cout << "Unknown notification " << std::endl;
    }
}

bool ManagementAlgorithm::LoadOrthophoto(Region_Of_Mission rom)
{
    //In case of need for more updated orthophoto, algo calls this method.
    //This method connects to the cloud and brings the model.
    // When model is ready, signal to the algorithm module.
    // with method or message OrthoReady()
    std::cout<<"ManagementAlgorithm::LoadOrthophoto called with param:"<<rom<<std::endl;

    return true;

}

bool ManagementAlgorithm::LoadWPSModel(Region_Of_Mission rom)
{
    //In case of need for more updated WPS model, algo calls this method.
    //This method connects to the cloud and brings the model.
    // When model is ready, signal to the algorithm module.
    // with method or message WPS_Ready()
    std::cout<<"ManagementAlgorithm::LoadWPSModel called with param:"<<rom<<std::endl;

    return true;
}

