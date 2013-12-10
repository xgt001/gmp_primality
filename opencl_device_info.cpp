#include <stdio.h>
#include <stdlib.h>
#include <Cl/cl.h>
#include <string>
#include <iostream>
using namespace std;
int main()
{
char s[40];
char* platform_info;
size_t ext_size;
cl_device_id *device;
cl_platform_id for_device;
char name[300], extension_data[4096];
cl_ulong global_mem_size;
int foo ;
cl_platform_id *platform;
cl_uint total_plats;
cl_uint total_devices = 0;
cl_bool avail;

  clGetPlatformIDs(3,NULL,&total_plats);

  clGetPlatformIDs(3,&for_device,NULL);
    platform = (cl_platform_id*)malloc(sizeof(cl_platform_id)*total_plats);

  clGetPlatformIDs(total_plats,platform,NULL);
  printf ("%d \n",total_plats);

  clGetPlatformInfo(platform[0],CL_PLATFORM_NAME,sizeof(s),&s,NULL);

 foo = clGetPlatformInfo(platform[0],CL_PLATFORM_EXTENSIONS,0,NULL,&ext_size);


platform_info = (char*)malloc(ext_size);

 clGetPlatformInfo(platform[0],CL_PLATFORM_EXTENSIONS,ext_size,platform_info,NULL);

cout << s << endl; // S => Platform number

cout << platform_info <<endl;

// Identify the number of devices and save it to total_devices
clGetDeviceIDs(for_device,CL_DEVICE_TYPE_ALL,0,NULL,&total_devices);

 // ALLOCATE memory for devices
device = (cl_device_id*)malloc(sizeof(cl_device_id*)*total_devices);
clGetDeviceIDs(for_device,CL_DEVICE_TYPE_ALL,total_devices,device,NULL);
for(int i = 0; i < total_devices;i++)
{

        clGetDeviceInfo(device[i],CL_DEVICE_NAME,sizeof(name),name,NULL);
        clGetDeviceInfo(device[i],CL_DEVICE_EXTENSIONS,sizeof(extension_data),extension_data,NULL);
        clGetDeviceInfo(device[i],CL_DEVICE_AVAILABLE,sizeof(avail),&avail,NULL);
        clGetDeviceInfo(device[i],CL_DEVICE_GLOBAL_MEM_SIZE,sizeof(global_mem_size),&global_mem_size,NULL);


        cout.width(75);
        cout.fill('*');
        cout << "\n" ;
        cout << "Device Name is " << name <<endl;
        cout << "Supported OPENCL Extensions: " << extension_data<<endl;
        cout << "Device Memory Size is" << global_mem_size << endl;
        if(avail)
        cout << "With Supported Compiler" << endl;
        cout << endl << endl;
}



cout << total_devices << endl;
  return 0;

}
