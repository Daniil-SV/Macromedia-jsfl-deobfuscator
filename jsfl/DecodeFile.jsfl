var inputFileURI = fl.browseForFileURL("open", "Obfuscated JSFL file", "Flash JavaScript", "jsfl");
var outputFileURI = fl.browseForFileURL("save", "JSFL file", "Flash JavaScript", "jsfl");

(function(){
	if (inputFileURI == outputFileURI)
	{
		alert("Input and output are the same");
		return;
	}

	var [succes, message] = MJD.decode(FLfile.uriToPlatformPath(inputFileURI), FLfile.uriToPlatformPath(outputFileURI));
	if (!succes)
	{
		alert(message)
	}
})()

