#include <gtest/gtest.h>
#include "../ProductsLib/cProducts.h"
#include "../ProcessOrdersLib/cProcessOrder.h"
#include <windows.h>

typedef void (*RunTestsFunc)();

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
    // Load the DLL
    HMODULE hDll = LoadLibrary(TEXT("ProcessOrdersLib_DynamicLinkLibrary.dll"));
    if (hDll) {

        FreeLibrary(hDll);
    }
    else {
        std::cerr << "Could not load the DLL." << std::endl;
    }
	return RUN_ALL_TESTS();
}