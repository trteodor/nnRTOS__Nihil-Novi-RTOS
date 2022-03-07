

SRC+= unit-tests/AnotherSampleFileToUT/test_ASFile.c   
SRC+= unit-tests/AnotherSampleFileToUT/test_runnerASFile.c 
SRC+= unit-tests/AnotherSampleFileToUT/test_main.c 


SRC+= examples/MCU_CoreWFI/Src/AnotherSampleFile.c


INC_DIR+= -Iexamples/MCU_CoreWFI/Inc/ 

 

COVERAGE_SOURCEDIR :=
COVERAGE_SOURCEDIR += examples/MCU_CoreWFI/Src


MOCKED_HEADER +=  examples/MCU_CoreWFI/Inc/AnotherSampleFile.h
MOCKED_HEADER +=  examples/MCU_CoreWFI/Inc/SampleFileToUT.h


MOCKED_SOURCE +=  $(BUILD_DIR_UT)/cmock/mock_SampleFileToUT.c


SRC+= $(MOCKED_SOURCE)
