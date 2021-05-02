# intel-sgx

# manjaro

1. Update auf Kernel 5.12
2. Download driver 2.11 and sdk von https://download.01.org/intel-sgx/sgx-linux/2.13/distro/ubuntu20.04-server/
3. Beide installieren
4. https://github.com/intel/linux-sgx clonen
5. In den Ordner SampleCode/SampleEnclave navigieren
6. `source /opt/intel/sgxsdk/environment`
7. `make SGX_MODE=SIM`
8. `./app`