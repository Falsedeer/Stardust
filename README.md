# Stardust
<img src="https://raw.githubusercontent.com/Falsedeer/Stardust/main/Picture/banner.png" width="622" height="375"/>  

---  

> Stardust, also known as 星屑(ほしくず).  
> means the night sky inlaid with shining star,   
> which is commonly used to describe a feeling of magical and ethereality in literature.  

__Cast the spell and let the magic begin !__  
__Then be attached to the unknown friend over the hill and far away !__

# DESC:  
Stardust is a lightweight, and fully functional reverse shell coded in C,  
which currently only support basic feature of command execution (Ver-0.1.2).  
![](https://github.com/Falsedeer/Stardust/blob/main/Picture/2.png)
The default opened shell of Stardust will be cmd.exe,  
however it is possible to switch to powershell by typing "powershell" in the console.  
![](https://github.com/Falsedeer/Stardust/blob/main/Picture/3.png)
During the execution of Stardust, 
the process will remain stealth on the infected host during the whole operating time,  
everything will be running in background,  
nothing will be shown in dock, neither a flash of command prompt on execution.  
</br>
And after establishing the connection,  
the only way to kill Stardust will be using Task Manager,  
forcing the process to halt or be killed.  
</br>
Without any interuption during execution,  
Stardust will exit gracefully by closing created process, 
and releasing occupied memory space before program exit,  
after the connection between the server got terminated.
![](https://github.com/Falsedeer/Stardust/blob/main/Picture/4.png)
Remmber to use the latest release(Ver-0.1.2) of Stardust in order to have the best experience.  
![](https://raw.githubusercontent.com/Falsedeer/Stardust/main/Picture/1.png)

# Usage:
The project file of Stardust included is ought to be open in UEStudio,  
or it can be compiled under windows by using MinGW GCC by linking library "ws2_32",  
and specifying it a GUI program. 

# ToDo:
- Add encryption supprort  
- Add build-in command support
- Add interactive command support
- Add keylogger module  
- Add DLL Injection module  
- Add anti-debugging module  
- Add anti-AV module  

