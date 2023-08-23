workspace "jsfl-deobfuscator"
    configurations {
        "Debug",
        "Release"
    }

	system "windows"
	architecture "x86_64"

	project "deobfuscator"
		kind "SharedLib"

		language "C++"
		cppdialect "C++17"

		targetdir "%{wks.location}/build/bin/%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}/%{prj.name}"
		objdir "%{wks.location}/build/obj/%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}/%{prj.name}"

		files {
			"include/**.h",
			"src/**.cpp"
		}

		includedirs {
			"include"
		}
		
		targetname ("MJD")

		filter "configurations:Debug"
			defines { "DEBUG" }
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines { "NDEBUG" }
			runtime "Release"
			optimize "on"

