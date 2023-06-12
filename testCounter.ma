[top]
components : counter@counter
Out : countOut
In : cam1
In : cam2
In : cam3
In : cam4
Link : countOut@counter countOut
Link : cam1 cam1@counter
Link : cam2 cam2@counter
Link : cam3 cam3@counter
Link : cam4 cam4@counter  


[counter]
preparation : 00:00:00:10
