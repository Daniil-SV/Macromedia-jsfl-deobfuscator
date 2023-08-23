//var inputFolder = "C:/Program Files/Adobe/Adobe Animate 2022"
//var outputFolder = "C:/JSFL"

var inputFolderURI = fl.browseForFolderURL("Select a input folder") + "/";//FLfile.platformPathToURI(inputFolder)
var outputFolderURI = fl.browseForFolderURL("Select a output folder") + "/";

function DecodeFolder(inputURI, outputURI)
{
	var files = FLfile.listFolder(inputURI, "files");
	var directories = FLfile.listFolder(inputURI, "directories");

	for (var i = 0; directories.length > i; i++)
	{
		var directory = directories[i];
		
		var inputDirectoryPathURI = inputURI + "/" + directory;
		var outputDirectoryURI = outputURI + "/" + directory;
		
		FLfile.createFolder(outputDirectoryURI);
		
		DecodeFolder(inputDirectoryPathURI, outputDirectoryURI);
	}

	for (var i = 0; files.length > i; i++)
	{
		var name = files[i];
		var nameSplit = name.split(".");
		
		if (nameSplit[nameSplit.length - 1] == "jsfl")
		{
			fl.trace(name);
			
			var inputFileURI = inputURI + "/" + name;
			var outputFileURI = outputURI + "/" + name;
			var [succes, message] = MJD.decode(FLfile.uriToPlatformPath(inputFileURI), FLfile.uriToPlatformPath(outputFileURI));
			
			var consoleMessage = ""
			if (succes){consoleMessage += "Succes"} else {consoleMessage += "Fail"};
			consoleMessage += ": " + message;
			fl.trace(consoleMessage);
			//fl.trace(`${succes ? "Succes" : "Fail"}: message`);			
		}
	}
}

function ClearEmptyFolders(pathURI)
{
	var files = FLfile.listFolder(pathURI, "files");
	var directories = FLfile.listFolder(pathURI, "directories");

	for (var i = 0; directories.length > i; i++)
	{
		var directory = directories[i];
		directoryURI = pathURI + "/" + directory;
		ClearEmptyFolders(directoryURI);
	}

	if (FLfile.listFolder(pathURI).length == 0)
	{
		FLfile.remove(pathURI);
	}
}

DecodeFolder(inputFolderURI, outputFolderURI);
ClearEmptyFolders(outputFolderURI)
