## Readme for Armadillo Toolbox interfacing with Scilab

**Milestone 5 requirements must be satisfied for smooth functioning of armadillo**

[Requirements Installation check video link](https://drive.google.com/file/d/13yo--zI0OP__SlnwNPVmZ3yC3bp9vjBS/view?usp=sharing)

[Toolbox sample execution video link](https://drive.google.com/file/d/18WG02C8oom9Kb5p-y5BWr5rmU1lvRQzR/view?usp=sharing)

### Readme for Armadillo Installation


**Both directories inside the milestone 5 zip have their corresponding ReadMe files with the required informations**

**Kindy deactivate anaconda if it is installed, before proceeding further cmd: conda deactivate**

**g++ version - 7.5.0 or above**

**c++14 standard**

**OS - Ubuntu 18 or 19.10**

### 1: Linux: Installation for Armadillo

**Don't include " ** " in the commands while executing in the terminal**


* Step 1:
  Ensure a C++ compiler is installed on your system.
  
		**sudo apt install g++**
		or
		**sudo apt install build-essential**

If already installed, check the installation by following command
	$ **g++ -v**

* Step 2:
  Ensure the CMake tool is installed on your system.
  You can download it from http://www.cmake.org
  or (preferably) install it using your package manager.
  - On Linux-based systems, you can get CMake using dnf, yum, apt, aptitude, ...
	
	**sudo apt-get install cmake**

If already installed, check the installation by following command
$ **cmake -version**

* Step 3:
  Ensure LAPACK and BLAS (or preferably OpenBLAS) are installed on your system.

  - For better performance, we recommend installing the OpenBLAS library.
    See http://www.openblas.net/ 

**-----------------------------------------------------------------------------------**
### 2: Linux: Installation for OpenBLAS
	**OpenBLAS-0.3.9** or **OpenBLAS-0.3.7**

Method 1:

Open a terminal window, change into the OpenBLAS directory that was created
  by unpacking the OpenBLAS archive, and do the following:

	Step 1: **sudo apt-get install liblapack-dev**

	Step 2:	**sudo apt-get install libblas-dev**

	Step 3:	**make**

	Step 4:	**sudo make install**

Method 2 (Alternate):
Simple Alternate method for installing OpenBLAS using synaptic GUI for installing package.

	step 1: **sudo apt-get update**
	
	step 2: **sudo apt-get install synaptic**
	
	step 3: **sudo synaptic**
	
The above commands will install synaptic package manager in your Linux system and opens it. In synaptic GUI window do the followings,
		
	step 4: click reload to refresh package list
	
	step 5: search for the packages lapack-dev and libblas-dev and click the checkbox in front of that package then click mark for installation. you have to do this for both the packages.
	Note: Green checkbox indicates that the package is already installed*
		
	step 6: click apply. It will download and install the marked packages automatically.

**-----------------------------------------------------------------------------------**


  - It is also necessary to install the corresponding development
    files for each library. For example, when installing the "lapack"
    package, also install the "lapack-devel" or "lapack-dev" package.
	
	**sudo apt-get install liblapack-dev**
	**sudo apt-get install libblas-dev**
  
* Step 4:
  Open a terminal window, change into the armadillo directory that was created
  by unpacking the armadillo archive, and do the following:

    		**" cmake . "**

  - The full stop separated from "cmake" by a space is important.

  - CMake will detect which relevant libraries are installed on your system
    (eg. OpenBLAS, LAPACK, SuperLU, ARPACK, etc)
    and will modify Armadillo's configuration correspondingly.
    CMake will also generate the Armadillo run-time library,
    which is a wrapper for all the detected libraries.

  - By default, cmake assumes that the Armadillo library and the
    corresponding header files are going to be installed in the default 
    system directory (eg. in the /usr hierarchy in Linux-based systems).
    If you wish to install the library and headers in an alternative directory,
    use the additional option CMAKE_INSTALL_PREFIX in this form:

    cmake . -DCMAKE_INSTALL_PREFIX:PATH=alternative_directory

  - If you need to re-run cmake, it's a good idea to first delete the
    "CMakeCache.txt" file (not "CMakeLists.txt").

  - Caveat: out-of-tree builds are currently not fully supported;
     eg, creating a sub-directory called "build" and running cmake ..
     from within "build" is currently not supported.

  - Caveat: if you are installing Armadillo in a non-system directory,
    make sure your C++ compiler is configured to use the "lib" and "include"
    sub-directories present within this directory.  Note that the "lib"
    directory might be named differently on your system.
    On recent 64 bit Debian & Ubuntu systems it is "lib/x86_64-linux-gnu".
    On recent 64 bit Fedora & RHEL systems it is "lib64".

* Step 5:
  To generate the run-time armadillo library, type the following command:

    **make**

* Step 6:
  If you and have access to root/administrator/superuser privileges
  (ie. able to use "sudo") and didn't use the CMAKE_INSTALL_PREFIX option,
  type the following command:

    **sudo make install**

  If you don't have root/administrator/superuser privileges,
  make sure that you use the CMAKE_INSTALL_PREFIX option in Step 4,
  and type the following command:

    **make install**


###-----------------------------------------------------------------------------------###

### Toolbox interfacing - Toolbox name - "armadilloToolbox"

	**Kindly check the video walkthrough for clearer understanding "MilestoneFive Demo Walkthrough.mp4" the video walksthrough on loading the external library as toolbox into scilab and a demo for help pages for the toolbox functions**
	**Video shows the first 20 example functions out of the 20 using help page and a sample example sce file execution**

			***Scilab version - 6.1.0***


	**Compile the external library**


Step 1: **"Go to the <MilestoneFive/external-library> dir"**

Step 2: **"Execute the <runT.sh> shell script"**
		**" ./runT.sh "**

Step 3: **"After successful compilation copy the <thirdparty> folder to this location <MilestoneFive/armadilloToolbox> to add the library to the toolbox"**

Step 4: **"Follow the below Scilab instructions to proceed further"**



	**Start Scilab from "/bin" dir of scilab**


Step 1: **"Select <File> option from top left corner"**

Step 2: **"Select <Browse for new> option"**

Step 3: **"Browse to the dir <MilestoneFive/armadilloToolbox> and click ok"**

Step 4: **"Once inside the above mentioned dir execute the below commands"**
		
		**" exec builder.sce "**
		
		**" exec loader.sce "**
		
	**Notice for errors**

Step 5: **"After successful execution of the above commands the toolbox will be loaded into Scilab"**

Step 6: **"Run/Test these functions through help section or using examples folder given in scilab MilestoneFive"**

