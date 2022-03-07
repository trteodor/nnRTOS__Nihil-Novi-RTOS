

SRC+= unit-tests/SampleFileToUT_UnitTests/test_SFToUT.c   
SRC+= unit-tests/SampleFileToUT_UnitTests/test_runnerSFToUT.c 
SRC+= unit-tests/SampleFileToUT_UnitTests/test_main.c 


SRC+= examples/MCU_CoreWFI/Src/SampleFileToUT.c 


INC_DIR+= -Iexamples/MCU_CoreWFI/Inc/


COVERAGE_SOURCEDIR :=
COVERAGE_SOURCEDIR +=examples/MCU_CoreWFI/Src


MOCKED_HEADER +=  examples/MCU_CoreWFI/Inc/AnotherSampleFile.h
MOCKED_HEADER +=  examples/MCU_CoreWFI/Inc/SampleFileToUT.h


MOCKED_SOURCE +=  $(BUILD_DIR_UT)/cmock/mock_AnotherSampleFile.c


SRC+= $(MOCKED_SOURCE)
