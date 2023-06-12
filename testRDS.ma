[top]
components : CamWithDetectorN CamWithDetectorS CamWithDetectorW CamWithDetectorE trafficlights@trafficlights counter@counter
Out : countOut
Out : dataN
Out : dataS
Out : dataW
Out : dataE
In : svN
In : svS
In : svW
In : svE
Link : svN sv@CamWithDetectorN
Link : svS sv@CamWithDetectorS
Link : svE sv@CamWithDetectorE
Link : svW sv@CamWithDetectorW
Link : redNS@trafficlights red@CamWithDetectorN
Link : redNS@trafficlights red@CamWithDetectorS
Link : redEW@trafficlights red@CamWithDetectorE
Link : redEW@trafficlights red@CamWithDetectorW
Link : counter@CamWithDetectorN cam1@counter
Link : counter@CamWithDetectorS cam2@counter
Link : counter@CamWithDetectorE cam3@counter
Link : counter@CamWithDetectorW cam4@counter
Link : countOut@counter countOut
Link : data@CamWithDetectorN dataN
Link : data@CamWithDetectorS dataS
Link : data@CamWithDetectorE dataE
Link : data@CamWithDetectorW dataW

[CamWithDetectorN]
components : detectorN@detector camsystemN@camsystem
Out : counter
Out : data
In : red
In : sv
Link : sv sv@detectorN
Link : red red@camsystemN
Link : emd@detectorN emd@camsystemN
Link : counter@camsystemN counter
Link : data@camsystemN data

[CamWithDetectorS]
components : detectorS@detector camsystemS@camsystem
Out : counter
Out : data
In : red
In : sv
Link : sv sv@detectorS
Link : red red@camsystemS
Link : emd@detectorS emd@camsystemS
Link : counter@camsystemS counter
Link : data@camsystemS data

[CamWithDetectorE]
components : detectorE@detector camsystemE@camsystem
Out : counter
Out : data
In : red
In : sv
Link : sv sv@detectorE
Link : red red@camsystemE
Link : emd@detectorE emd@camsystemE
Link : counter@camsystemE counter
Link : data@camsystemE data

[CamWithDetectorW]
components : detectorW@detector camsystemW@camsystem
Out : counter
Out : data
In : red
In : sv
Link : sv sv@detectorW
Link : red red@camsystemW
Link : emd@detectorW emd@camsystemW
Link : counter@camsystemW counter
Link : data@camsystemW data

[detectorN]
preparation : 00:00:00:10

[detectorS]
preparation : 00:00:00:10

[detectorE]
preparation : 00:00:00:10

[detectorW]
preparation : 00:00:00:10

[camsystemN]
preparation : 00:00:00:10

[camsystemS]
preparation : 00:00:00:10

[camsystemE]
preparation : 00:00:00:10

[camsystemW]
preparation : 00:00:00:10

[trafficlights]
greenTime : 00:00:07:00
yellowTime : 00:00:03:00

[counter]
preparation : 00:00:00:10
