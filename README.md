
# Intel(R) Software Guard Extensions for Linux* OS
## Ubuntu 20.04 LTS 64-bit Desktop
This documentation is a quick installation guide to run Intel(R) Software Guard Extensions on Ubuntu 20.04 LTS 64-bit Desktop with disabled Flexible Launch Control (FLC) support.

### Prerequisites
To install the Intel® SGX PSW, first install the following tools: 

``$ sudo apt-get install libssl-dev libcurl4-openssl-dev libprotobuf-dev``

To install the Intel® SGX SDK, install the following tools:
``$ sudo apt-get install build-essential python-is-python3``

### Install Intel® SGX Driver Installation
Download the DCAP driver from https://01.org/intel-software-guard-extensions/downloads 
You can find the DCAP version in the `driver_readme.txt` file. 

Set the protections to allow for the .bin file execution:
``$ chmod 777 sgx_linux_x64_driver_<version>.bin``

Run the following command:
``$ sudo./sgx_linux_x64_driver_<version>.bin``

Reboot your system. 

### Intel® SGX Platform SoftWare (PSW) Installation
Add the following repository to your sources:
``$ echo 'deb [arch=amd64] https://download.01.org/intel-sgx/sgx_repo/ubuntu focal main' | sudo tee /etc/apt/sources.list.d/intel-sgx.list``

Add the key to the list of trusted keys used by the apt to authenticate packages:
``$ wget https://download.01.org/intel-sgx/sgx_repo/ubuntu/intel-sgx-deb.key``
``$ sudo apt-key add intel-sgx-deb.key``

Update the apt and install the packages:
``$ sudo apt-get update``

Install launch service:
``$ sudo apt-get install libsgx-launch libsgx-urts``

Install EPID-based attestation service:
``$ sudo apt-get install libsgx-epid``

Install algorithm agnostic attestation service
``$ sudo apt-get install libsgx-quote-ex``

### Install Intel® SGX SDK Installation
Download Intel® SGX SDK package from https://01.org/intel-software-guard-extensions/downloads 

Set the protections to allow for the .bin file execution:
``$ chmod 777 sgx_linux_x64_sdk_<version>.bin``

Install the SDK using the following command:
``$ sudo./sgx_linux_x64_sdk_<version>.bin``
 
Install the SDK in following directory:
``/opt/intel``

Run the following command:
``source /opt/intel/sgxsdk/environment``

### Find further Documentation

[Intel(R) SGX for Linux* OS](https://01.org/intel-softwareguard-extensions) project home page on [01.org](https://01.org)

[Intel(R) SGX Programming Reference](https://software.intel.com/sites/default/files/managed/7c/f1/332831-sdm-vol-3d.pdf)

## manjaro

1. Update auf Kernel 5.12
2. Download driver 2.11 and sdk von https://download.01.org/intel-sgx/sgx-linux/2.13/distro/ubuntu20.04-server/
3. Beide installieren
4. https://github.com/intel/linux-sgx clonen
5. In den Ordner SampleCode/SampleEnclave navigieren
6. `source /opt/intel/sgxsdk/environment`
7. `make SGX_MODE=SIM`
8. `./app`




## Install Eclipse Plugin
Intel delivers a plugin for enclave developers, which uses the Eclipse IDE. It supports developers to maintain SGX code. This guide shows you how to install the plugin and how to create an SGX Hello World application with this plugin.

### Prerequisites
* Eclipse 
** Use the C/C++ package, which can be found [here](https://www.eclipse.org/downloads/packages/)
* OpenSSL
* Intel SGX SDK for Linux OS

### Install Plugin
* Download the plugin from [Intel](https://01.org/intel-software-guard-extensions/downloads)
* Open Eclipse and go to Help menu → Install New Software ... on the menu bar.
* The install dialog appears. Click the Add ... button to open the Add Repository dialog
* Add a meaningful name like Intel SGX Eclipse Plugin and click on the Archive ... button
* Select the previously downloaded plugin and hit open and click Add
* In the install dialog select the plugin and install the plugin 

### Create Hello World 
* Go to File → New → Other...
* The project wizard appears. Select the C++ Project inside the C/C++ projects with Intel(R) SGX Enabled folder
* Hit next and set a project name and select Empty Project (default value) in the project type list
* Go through the wizard until the Finish button is enabled
* Open the context menu by clicking on the project with the right mouse button and go to Intel(R) Software Guard Extensions Tools → Add Intel(R) SGX Enclave
* Add the enclave name and hit OK on the appearing dialog
* A new folder is created with a full working skeleton of SGX
* You can build it by using the hammer icon in the toolbar. 
* To run the application click on your project and select Run As → Local C/C++ Application

If you get an error message like `error while loading shared libraries: libsgx_urts_sim.so: cannot open shared object file: No such file or directory` you have to do the following steps:
* Edit the configuration of executable
** The little gear icon next to the name of your application
* Open the tab Environment
* Add the variable LD_LIBRARY_PATH and the value pointing to your sdk_libs e.g. /opt/intel/sgxsdk/sdk_libs

Run the application again and you will see in the console the name of your enclave name and the output `Application ran with success`

