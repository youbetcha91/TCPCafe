#pragma once

#include <nfd.h>

namespace FileDialogue
{
    void Init()
    {
        NFD_Init();
    }

    void Cleanup()
    {
        NFD_Quit();
    }

    std::string GetPathForOpen()
    {
        std::string output = "";
        nfdu8char_t* outPath;
        nfdu8filteritem_t filters[1] = {{ "TCPCafe File", "cafe" }};
        nfdopendialogu8args_t args {filters, 1, nullptr, {}};
        nfdresult_t result = NFD_OpenDialogU8_With(&outPath, &args);

        if (result == NFD_OKAY)
        {
            if(outPath != nullptr)
            {
                output = std::string(outPath);
            }
            NFD_FreePathU8(outPath);
        }
        return output;
    }

    std::string GetPathForSave(const std::string& defaultName)
    {
        std::string output = "";
        nfdu8char_t* outPath;
        nfdu8filteritem_t filters[1] = {{ "TCPCafe File", "cafe" }};

        std::string defaultFileName = defaultName.empty() ? "NetworkNodes.cafe" : defaultName;

        nfdsavedialogu8args_t args = {filters, 1,nullptr, defaultFileName.c_str(), {}};

        nfdresult_t result = NFD_SaveDialogU8_With(&outPath, &args);

        if (result == NFD_OKAY)
        {
            if(outPath != nullptr)
            {
                output = std::string(outPath);
            }
            NFD_FreePathU8(outPath);
        }
        
        return output;
    }
}

