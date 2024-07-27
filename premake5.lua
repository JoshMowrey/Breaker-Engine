workspace "Breaker-Engine"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }
    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Breaker"
    location "Breaker-Engine"
    kind "SharedLib"
    language "C++"

    targetdir("Bin/" .. outputdir .. "/%{prj.name}")
    objdir("BinInt/" .. outputdir .. "/%{prj.name}")
    
    pchheader "brpch.h"
    pchsource "Breaker-Engine/src/brpch.cpp"

    files {
        "Breaker-Engine/src/**.h",
        "Breaker-Engine/src/**.hpp",
        "Breaker-Engine/src/**.c",
        "Breaker-Engine/src/**.cpp" 
    }

    includedirs {
        "Breaker-Engine/src",
        "Breaker-Engine/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "BR_BUILD_DLL", 
            "BR_PLATFORM_WINDOWS"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    
    filter "configurations:Debug"
        defines "BR_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "BR_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "BR_DIST"
        optimize "On"   




project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    


    targetdir("Bin/" .. outputdir .. "/%{prj.name}")
    objdir("BinInt/" .. outputdir .. "/%{prj.name}")
    

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.c",
        "%{prj.name}/src/**.cpp" 
    }

    includedirs {
        "Breaker-Engine/vendor/spdlog/include",
        "Breaker-Engine/src"
    }

    links {
        "Breaker"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "BR_PLATFORM_WINDOWS"
        }

    
    filter "configurations:Debug"
        defines "BR_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "BR_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "BR_DIST"
        optimize "On"   
    


    

