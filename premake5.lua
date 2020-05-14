workspace "York"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "York/vendor/GLFW/include"
IncludeDir["Glad"] = "York/vendor/Glad/include"
IncludeDir["ImGui"] = "York/vendor/imgui"

include "York/vendor/GLFW"
include "York/vendor/Glad"
include "York/vendor/ImGui"

project "York"
	location "York"
	kind "SharedLib"
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ykpch.h"
	pchsource "York/src/ykpch.cpp"

	files
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links 
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines 
		{
			"YK_PLATFORM_WINDOWS",
			"YK_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "YK_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "YK_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "YK_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"York/vendor/spdlog/include",
		"York/src"
	}

	links 
	{
		"York"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines 
		{
			"YK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "YK_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "YK_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "YK_DIST"
		runtime "Release"
		optimize "On"
