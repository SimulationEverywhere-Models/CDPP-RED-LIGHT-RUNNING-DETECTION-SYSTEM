[top]
components : detector@detector camsystem@camsystem
Out : counter
Out : data
In : red
In : sv
Link : sv sv@detector
Link : red red@camsystem
Link : emd@detector emd@camsystem
Link : counter@camsystem counter
Link : data@camsystem data


[detector]
preparation : 00:00:00:10

[camsystem]
preparation : 00:00:00:10
