#include<bits/stdc++.h>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>



using namespace std;
static int endDeviceId=0;
class Device{
public:
    int deviceId;
    string displayName;
 	string Ip;
	string macAddress;
    int connectedToDevice;
};
class EndDevices{
	Device deviceInfo;
public :	
    EndDevices(){
        deviceInfo.deviceId = endDeviceId;
        int temp = endDeviceId;
        string converter;
        stringstream ss;
        ss<<temp;
        ss>>converter;
        deviceInfo.displayName = "PC"+converter;
        deviceInfo.connectedToDevice = -1;
        cout<<"\n .......Creating Device.....\n";
        cout<<" Device Id : "<<deviceInfo.deviceId<<" ......Display Name : "<<deviceInfo.displayName<<"\n\n";
        endDeviceId++;
    }
    
	void setInfo(){
        int choice;
		
        cout<<"\n .....Enter Device Details.....\n";
        cout<<" Device Id : "<<deviceInfo.deviceId<<"\n";
        cout<<" .....Assigning ip address...... \n";
            
            
        cout<<" Enter Ip address : ";
        cin>>deviceInfo.Ip;
        cout<<" Ip address allocated : "<<deviceInfo.Ip<<"\n";
                    
                
                
            
        cout<<" .....Assigning mac address...... \n";
            
        cout<<" Enter mac address : ";
        cin>>deviceInfo.macAddress;
        cout<<" Mac address allocated : "<<deviceInfo.macAddress<<"\n";
                
	}
    Device getDeviceInfo(){
        return deviceInfo;
    }
    int getDeviceID()
    {
        return deviceInfo.deviceId;
    }
    string getDisplayName()
    {
        return deviceInfo.displayName;
    }
    void setConnection(int connectDevice,int endDeviceId,int hubDeviceId,int switchDeviceId, int bridgeDeviceId)
    {
        deviceInfo.connectedToDevice = connectDevice;
        if(connectDevice<endDeviceId)
            {
                cout<<"\n .....Connection Established.....Between "<<deviceInfo.displayName<<" and PC"<<connectDevice;
            }
            else if(connectDevice>=100 && connectDevice<hubDeviceId)
            {
                 cout<<"\n .....Connection Established.....Between "<<deviceInfo.displayName<<" and Hub"<<connectDevice-100;
            }
            else if(connectDevice>=200 && connectDevice<switchDeviceId)
            {
                 cout<<"\n .....Connection Established.....Between "<<deviceInfo.displayName<<" and Switch"<<connectDevice-200;
            }
            else if(connectDevice>=300 && connectDevice<bridgeDeviceId)
                {
                    cout<<"\n X....Connection Established.....Between "<<deviceInfo.displayName<<" and Bridge"<<connectDevice-300;
                }
        
    }
    int getConnection()
    {
        return deviceInfo.connectedToDevice;
    }

    void displayDeviceInfo(){
        cout<<"\n ......Displaying details of the device ......\n";
        cout<<" Device Id : "<<deviceInfo.deviceId<<"\n";
        cout<<" Display Name : "<<deviceInfo.displayName<<"\n";
        cout<<" Device ip address : "<<deviceInfo.Ip<<"\n";
        cout<<" Device mac address : "<<deviceInfo.macAddress<<"\n";
        if(deviceInfo.connectedToDevice == -1)
            cout<<" No connection is established\n";
        else
            cout<<" Device is connected to : "<<deviceInfo.connectedToDevice<<"\n";
    }
    
};

void displayAllEndDevices(vector<EndDevices> obj){
        if(obj.size()==0)
        {
            cout<<"\n\n No end device is added \n\n";
            return;
        }
        cout<<"\n\n ......Diaplaying all the end devices......";
        cout<<"\n -----------------------------------------------------\n";
        for(int i=0;i<obj.size();i++)
        {
            obj[i].displayDeviceInfo();
        }
        cout<<"\n -----------------------------------------------------\n";
}








static int hubDeviceId = 100;
class HDevice
{
public :
    int hubId;
    string displayName;
    vector<int> connectedToDevices;
};
class Hub
{
    HDevice hubInfo;
public: 
        Hub(){
        hubInfo.hubId = hubDeviceId;
        int temp = hubDeviceId-100;
        string converter;
        stringstream ss;
        ss<<temp;
        ss>>converter;
        hubInfo.displayName = "Hub"+converter;
        cout<<"\n .......Creating Hub.....\n";
        cout<<" Device Id : "<<hubInfo.hubId<<" .....Display Name : "<<hubInfo.displayName<<"\n\n";
        hubDeviceId++;
    }
    int getHubId(){ return hubInfo.hubId;}
    string getDisplayName()
    {
        return hubInfo.displayName;
    }
    void setConnection(int connectDevice,int endDeviceId,int hubDeviceId,int switchDeviceId, int bridgeDeviceId)
    {
         bool flag = 0;
        for(int i = 0;i<hubInfo.connectedToDevices.size();i++)
        {
            if(connectDevice == hubInfo.connectedToDevices.at(i))
                flag = 1;
        }
        if(flag == 0)
        {
            hubInfo.connectedToDevices.push_back(connectDevice);
            if(connectDevice<endDeviceId)
            {
                cout<<"\n .....Connection Established.....Between "<<hubInfo.displayName<<" and PC"<<connectDevice;
            }
            else if(connectDevice>=100 && connectDevice<hubDeviceId)
            {
                 cout<<"\n .....Connection Established.....Between "<<hubInfo.displayName<<" and Hub"<<connectDevice-100;
            }
            else if(connectDevice>=200 && connectDevice<switchDeviceId)
            {
                 cout<<"\n .....Connection Established.....Between "<<hubInfo.displayName<<" and Switch"<<connectDevice-200;
            }
            else if(connectDevice>=300 && connectDevice<bridgeDeviceId)
                {
                    cout<<"\n .....Connection Established.....Between "<<hubInfo.displayName<<" and Bridge"<<connectDevice-300;
                }
            sort(hubInfo.connectedToDevices.begin(),hubInfo.connectedToDevices.end());
        }
        else
        {
            cout<<"\n ..Device is already Connected\n";
        }
    }
    
    vector<int> getConnections()
    {
        return hubInfo.connectedToDevices;
    }   

    void displayDeviceInfo(){
        cout<<"\n ...... Hub ......\n";
        cout<<" Device Id : "<<hubInfo.hubId<<"\n";
        cout<<" Device Name : "<<hubInfo.displayName<<"\n";
        if(hubInfo.connectedToDevices.size())
        {
            cout<<" Device is connected to devices : ";
            for(int i=0;i<hubInfo.connectedToDevices.size();i++)
            {
                cout<<hubInfo.connectedToDevices[i]<<" ";
            }
        cout<<"\n";
        }
        else
        {
            cout<<" No connection is established\n";
        }

    }
};
void displayAllHubs(vector<Hub> objHub){
        if(objHub.size()==0)
        {
            cout<<"\n\n No hub is added \n\n";
            return;
        }
        
        cout<<"\n\n ......Diaplaying all the Hubs......";
        cout<<"\n -----------------------------------------------------\n";
        for(int i=0;i<objHub.size();i++)
        {
            objHub[i].displayDeviceInfo();
        }
        cout<<"\n-----------------------------------------------------\n";
}






static int bridgeDeviceId = 300;
class BDevice
{
public :
    int bridgeId;
    string displayName;
    vector<int> connectedToDevices;
};
class Bridge
{
    BDevice bridgeInfo;
public: 
    Bridge(){
        bridgeInfo.bridgeId = bridgeDeviceId;
        int temp = bridgeDeviceId-300;
        string converter;
        stringstream ss;
        ss<<temp;
        ss>>converter;
        bridgeInfo.displayName = "Bridge"+converter;
        cout<<"\n .......Creating Bridge.....\n";
        cout<<" Device Id : "<<bridgeInfo.bridgeId<<" ......Display Name : "<<bridgeInfo.displayName<<"\n\n";
        bridgeDeviceId++;
    }
    int getbridgeId(){ return bridgeInfo.bridgeId;}
    string getDisplayName()
    {
        return bridgeInfo.displayName;
    }
    void setConnection(int connectDevice,int endDeviceId,int hubDeviceId,int switchDeviceId, int bridgeDeviceId)
    {
        bool flag = 0;
        if(bridgeInfo.connectedToDevices.size()<2)
        {
            for(int i = 0;i<bridgeInfo.connectedToDevices.size();i++)
            {
                if(connectDevice == bridgeInfo.connectedToDevices.at(i))
                    flag = 1;
            }
            if(flag == 0)
            {
                if(connectDevice<endDeviceId)
                { bridgeInfo.connectedToDevices.push_back(connectDevice);
                cout<<"\n X....Connection cannot be Established.....Between "<<bridgeInfo.displayName<<" and PC"<<connectDevice;
                }
                else if(connectDevice>=100 && connectDevice<hubDeviceId)
                {
                    bridgeInfo.connectedToDevices.push_back(connectDevice);
                    cout<<"\n .....Connection Established.....Between "<<bridgeInfo.displayName<<" and Hub"<<connectDevice-100;
                }
                else if(connectDevice>=200 && connectDevice<switchDeviceId)
                {
                    bridgeInfo.connectedToDevices.push_back(connectDevice);
                    cout<<"\n .....Connection Established.....Between "<<bridgeInfo.displayName<<" and Switch"<<connectDevice-200;
                }
                else if(connectDevice>=300 && connectDevice<bridgeDeviceId)
                {   bridgeInfo.connectedToDevices.push_back(connectDevice);
                    cout<<"\n X....Connection cannot be Established.....Between "<<bridgeInfo.displayName<<" and Bridge"<<connectDevice-300;
                }
            
                sort(bridgeInfo.connectedToDevices.begin(),bridgeInfo.connectedToDevices.end());
            }
            else
            {
                cout<<"\n ..Device is already Connected\n";
            }
        }
        else 
        {
            cout<<"\n .... Connections already completed \n";
        }
    }
    
    vector<int> getConnections()
    {
        return bridgeInfo.connectedToDevices;
    }   

    void displayDeviceInfo(){
        cout<<"\n ...... Bridge ......\n";
        cout<<" Device Id : "<<bridgeInfo.bridgeId<<"\n";
        cout<<" Device Name : "<<bridgeInfo.displayName<<"\n";
       if(bridgeInfo.connectedToDevices.size())
        {
            cout<<" Device is connected to devices : ";
            for(int i=0;i<bridgeInfo.connectedToDevices.size();i++)
            {
                cout<<bridgeInfo.connectedToDevices[i]<<" ";
            }
        cout<<"\n";
        }
        else
        {
            cout<<" No connection is established\n";
        }

    }
};
void displayAllbridges(vector<Bridge> objbridge){
        if(objbridge.size()==0)
        {
            cout<<"\n\n No Bridge is added \n\n";
            return;
        }
        cout<<"\n\n ......Diaplaying all the Bridgees......";
        cout<<"\n -----------------------------------------------------\n";
        for(int i=0;i<objbridge.size();i++)
        {
            objbridge[i].displayDeviceInfo();
        }
       cout<<"\n-----------------------------------------------------\n";
}




static int switchDeviceId = 200;
class SDevice
{
public :
    int switchId;
    string displayName;
    bool addressLearning;
    vector<int> connectedToDevices;
};
class Switch
{
    SDevice switchInfo;
public: 
    Switch(){
        switchInfo.switchId = switchDeviceId;
        switchInfo.addressLearning = 0;
        int temp = switchDeviceId-200;
        string converter;
        stringstream ss;
        ss<<temp;
        ss>>converter;
        switchInfo.displayName = "Switch"+converter;
        cout<<"\n .......Creating Switch.....\n";
        cout<<" Device Id : "<<switchInfo.switchId<<" ......Display Name : "<<switchInfo.displayName<<"\n\n";
        switchDeviceId++;
    }
    int getswitchId(){ return switchInfo.switchId;}
    string getDisplayName()
    {
        return switchInfo.displayName;
    }
    void setAddressLearning()
    {
        switchInfo.addressLearning = 1;
    }
    bool getAddressLearning()
    {
        return switchInfo.addressLearning;
    }
    void setConnection(int connectDevice,int endDeviceId,int hubDeviceId,int switchDeviceId, int bridgeDeviceId)
    {
        bool flag = 0;
        for(int i = 0;i<switchInfo.connectedToDevices.size();i++)
        {
            if(connectDevice == switchInfo.connectedToDevices.at(i))
                flag = 1;
        }
        if(flag == 0)
        {
            switchInfo.connectedToDevices.push_back(connectDevice);
            if(connectDevice<endDeviceId)
            {
                cout<<"\n .....Connection Established.....Between "<<switchInfo.displayName<<" and PC"<<connectDevice;
            }
            else if(connectDevice>=100 && connectDevice<hubDeviceId)
            {
                 cout<<"\n .....Connection Established.....Between "<<switchInfo.displayName<<" and Hub"<<connectDevice-100;
            }
            else if(connectDevice>=200 && connectDevice<switchDeviceId)
            {
                 cout<<"\n .....Connection Established.....Between "<<switchInfo.displayName<<" and Switch"<<connectDevice-200;
            }
            else if(connectDevice>=300 && connectDevice<bridgeDeviceId)
                {
                    cout<<"\n .....Connection Established.....Between "<<switchInfo.displayName<<" and Bridge"<<connectDevice-300;
                }
        
            sort(switchInfo.connectedToDevices.begin(),switchInfo.connectedToDevices.end());
        }
        else
        {
            cout<<"\n ..Device is already Connected\n";
        }
    }
    
    vector<int> getConnections()
    {
        return switchInfo.connectedToDevices;
    }   

    void displayDeviceInfo(){
        cout<<"\n ...... Switch ......\n";
        cout<<" Device Id : "<<switchInfo.switchId<<"\n";
        cout<<" Device Name : "<<switchInfo.displayName<<"\n";
       if(switchInfo.connectedToDevices.size())
        {
            cout<<" Device is connected to devices : ";
            for(int i=0;i<switchInfo.connectedToDevices.size();i++)
            {
                cout<<switchInfo.connectedToDevices[i]<<" ";
            }
        cout<<"\n";
        }
        else
        {
            cout<<" No connection is established\n";
        }

    }
};
void displayAllSwitches(vector<Switch> objSwitch){
        if(objSwitch.size()==0)
        {
            cout<<"\n\n No Switch is added \n\n";
            return;
        }
        cout<<"\n\n ......Diaplaying all the switches......";
        cout<<"\n -----------------------------------------------------\n";
        for(int i=0;i<objSwitch.size();i++)
        {
            objSwitch[i].displayDeviceInfo();
        }
       cout<<"\n-----------------------------------------------------\n";
}






int token = 0;
void accessControl(int deviceID,int endDeviceID)
{
    cout<<"\n .....Token Passing.....\n";
    while(token != deviceID)
    {
        cout<<"\nPassing token from PC"<<token<<" to -> PC"<<(token+1)%endDeviceID;
        token++;
        token = token%endDeviceID;
    }
}






static bool sendingAckNoSNW = 0;
void stopNwait_Sender(int,int);
int stopNwait_Receiver(int,int);

void stopNwait_Sender(int noPackets,int probability)
{
	int receivedAckNo = 0,totalTransmissions = 0;
	for (int packetNo = 0; packetNo < noPackets; packetNo++)
	{
		cout << "\n Sending Packet Number : " << packetNo << " Sequence Number : " << (packetNo % 2);
		receivedAckNo = stopNwait_Receiver(packetNo % 2,probability);
		totalTransmissions++;
		if ((packetNo % 2) == receivedAckNo)
		{
			if (rand() % 2 == 0)
				cout << "\n Packet Not Received .. Resending .. ";
			else
				cout << "\n Timed Out .. Resending .. ";
			packetNo--;
		}
		else
			cout << "\n Acknowledgment Received .. Sending Next .. \n";
	}
	cout<<"\n Total no. of transmission are : "<<totalTransmissions<<"\n";
	cout<<"\n Total no. of collisions are : "<<totalTransmissions - noPackets<<"\n";
}

int stopNwait_Receiver(int seqNo,int probability)
{
	if(rand()%100<=probability)
	{
		if (sendingAckNoSNW == seqNo)
		{
			cout << "\n Packet Received .. Sending Acknowledgment .. ";
			sendingAckNoSNW = !seqNo;
			return sendingAckNoSNW;
		}
		else
		{
			cout << "\n Packet Already Received .. Resending Acknowledgment .. ";
			return sendingAckNoSNW;
		}
	}
	return sendingAckNoSNW;
}





class path
{
public:
    int source;
    int intermediate;
    int destination;
};

int main()
{
    vector<EndDevices> obj;
    vector<Switch> objSwitch;
    vector<Hub> objHub;
    vector<Bridge> objBridge;
    int choice = 0,deviceID1=0,deviceID2=0,intermediateID=0,flowControl=0,noBroadcasts=0;
    int packets, seqBits,probability;
    double persistance;
    while(true)
    {
            cout<<"\n========= WELCOME ==========\n";
            cout<<"\n 1.End Device Operations\n";
            cout<<" 2.Switch Operations\n";
            cout<<" 3.Bridge Operations\n";
            cout<<" 4.Hub Operations\n";
            cout<<" 5.Create Connections\n";
            cout<<" 6.Data Transfer\n";
            cout<<" 7.Display All Devices\n";
            cout<<" 8.Exit\n";
            cout<<" Enter your choice : ";
            cin>>choice;

        if(choice == 1)
        {
            while(true)
            {
                cout<<"\n--------- END DEVICES OPERATIONS -----------\n";
                cout<<"\n 1.Add new Device\n";
                cout<<" 2.Show Device Info \n";
                cout<<" 3.Change device Configuration\n";
                cout<<" 4.Display all the end devices\n";
                cout<<" 5.exit\n";
                cout<<" Enter your choice : ";
                cin>>choice;
                if(choice==1)
                {
                    EndDevices tempObj;
                    tempObj.setInfo();
                    obj.push_back(tempObj);
                }

                else if( choice == 2)
                {
                    cout<<" Enter the device id : ";
                    cin>>deviceID1;
                    if(deviceID1>endDeviceId-1)
                        cout<<" Invalid device id\n";
                    else
                        obj[deviceID1].displayDeviceInfo();
                }
                else if (choice == 3)
                {
                    cout<<" Enter the device id : ";
                    cin>>deviceID1;
                    if(deviceID1>endDeviceId-1)
                        cout<<" Invalid device id\n";
                    else
                        obj[deviceID1].setInfo();
                }
                else if(choice == 4)
                {
                    displayAllEndDevices(obj);
                }
                else if ( choice == 5)
                {
                    break;
                }
                else
                {
                    cout<<" Invalid Choice.....Please try again\n\n";
                }    
            }
        }
        else if(choice == 2)
        {
            cout<<"\n--------- SWITCH OPERATIONS -------------\n";
            while(true)
            {
                cout<<"\n 1.Add a Switch\n";
                cout<<" 2.Show Specific Switch Info \n";
                cout<<" 3.Display all the Switches\n";
                cout<<" 4.Exit\n";
                cout<<" Enter your choice : ";
                cin>>choice;
                if(choice==1)
                {
                    Switch tempObj;
                    objSwitch.push_back(tempObj);
                }
                else if( choice == 2)
                {
                    cout<<" Enter the device id : ";
                    cin>>deviceID1;
                    if(deviceID1>switchDeviceId-1)
                        cout<<" Invalid device id\n";
                    else
                        objSwitch[deviceID1-200].displayDeviceInfo();
                }
                else if(choice == 3)
                {
                displayAllSwitches(objSwitch);
                }
                else if ( choice == 4)
                {
                    break;
                }
                else
                {
                    cout<<" Invalid Choice.....Please try again\n";
                }   
            }
        }
         else if(choice == 3)
        {
            cout<<"\n--------- Bridge OPERATIONS -------------\n";
            while(true)
            {
                cout<<"\n 1.Add a Bridge\n";
                cout<<" 2.Show Specific Bridge Info \n";
                cout<<" 3.Display all the Bridges\n";
                cout<<" 4.Exit\n";
                cout<<" Enter your choice : ";
                cin>>choice;
                if(choice==1)
                {
                    Bridge tempObj;
                    objBridge.push_back(tempObj);
                }
                else if( choice == 2)
                {
                    cout<<" Enter the device id : ";
                    cin>>deviceID1;
                    if(deviceID1>bridgeDeviceId-1)
                        cout<<" Invalid device id\n";
                    else
                        objBridge[deviceID1-300].displayDeviceInfo();
                }
                else if(choice == 3)
                {
                displayAllbridges(objBridge);
                }
                else if ( choice == 4)
                {
                    break;
                }
                else
                {
                    cout<<" Invalid Choice.....Please try again\n";
                }   
            }
        }
        else if(choice == 4)
        {
          cout<<"\n--------- HUB OPERATION -------------\n";
            while(true)
            {
                cout<<"\n 1.Add new Device\n";
                cout<<" 2.Show Device Info \n";
                cout<<" 3.Display all the Hub\n";
                cout<<" 4.exit\n";
                cout<<" Enter your choice : ";
                cin>>choice;
                if(choice==1)
                {
                    Hub tempObj;
                    objHub.push_back(tempObj);
                }
                else if( choice == 2)
                {
                    cout<<" Enter the device id : ";
                    cin>>deviceID1;
                    if(deviceID1>hubDeviceId-1)
                        cout<<" Invalid device id\n";
                    else
                        objHub[deviceID1-100].displayDeviceInfo();
                }
                else if(choice == 3)
                {
                displayAllHubs(objHub);
                }
                else if ( choice == 4)
                {
                    break;
                }
                else
                {
                    cout<<" Invalid choice.....Please try again\n";
                }   
            }
        }
        else if(choice == 5)
        {
         cout<<"\n--------- CREATE CONNECTIONS -------------\n";
            while(true)
            {
                cout<<"\n 1.Create Connections\n";
                cout<<" 2.Exit\n";
                cout<<" Enter you choice : ";
                cin>>choice;
                if(choice == 1)
                {
                    cout<<" Enter the device id of first device : ";
                    cin>>deviceID1;
                    cout<<" Enter the device Id to which device : "<<deviceID1<<" is to be connected : ";
                    cin>>deviceID2;
                    if(deviceID1<endDeviceId)
                    {
                        if(deviceID2<endDeviceId)
                        {
                            obj[deviceID1].setConnection(deviceID2, endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId); 
                            obj[deviceID2].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);      
                        }
                        else if (deviceID2>=100 && deviceID2<hubDeviceId)
                        {
                            obj[deviceID1].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                            objHub[deviceID2-100].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                        }
                        else if(deviceID2>=200 && deviceID2<switchDeviceId)
                        {
                            obj[deviceID1].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                            objSwitch[deviceID2-200].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                        }
                        else if (deviceID2>=300 && deviceID2<bridgeDeviceId)
                        {
                            obj[deviceID1].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                            objBridge[deviceID2-300].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                        }
                        else
                        {
                            cout<<"\n Invalid device Id entered for device 2\n";
                        }
                    }
                    else if (deviceID1>=100 && deviceID1<hubDeviceId)
                    {
                        if(deviceID2<endDeviceId)
                        {
                            objHub[deviceID1-100].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId); 
                            obj[deviceID2].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);      
                        }
                        else if (deviceID2>=100 && deviceID2<hubDeviceId)
                        {
                            objHub[deviceID1-100].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                            objHub[deviceID2-100].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                        }
                        else if(deviceID2>=200 && deviceID2<switchDeviceId)
                        {
                            objHub[deviceID1-100].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                            objSwitch[deviceID2-200].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                        }
                        else if (deviceID2>=300 && deviceID2<bridgeDeviceId)
                        {
                            objHub[deviceID1-100].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                            objBridge[deviceID2-300].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                        }
                        else
                        {
                            cout<<"\n Invalid device Id entered for device 2\n";
                        }
                    }
                    else if(deviceID1>=200 && deviceID1<switchDeviceId)
                    {
                        if(deviceID2<endDeviceId)
                        {
                            objSwitch[deviceID1-200].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId); 
                            obj[deviceID2].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);      
                        }
                        else if (deviceID2>=100 && deviceID2<hubDeviceId)
                        {
                            objSwitch[deviceID1-200].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                            objHub[deviceID2-100].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                        }
                        else if(deviceID2>=200 && deviceID2<switchDeviceId)
                        {
                            objSwitch[deviceID1-200].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                            objSwitch[deviceID2-200].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                        }
                        else if (deviceID2>=300 && deviceID2<bridgeDeviceId)
                        {
                            objSwitch[deviceID1-200].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                            objBridge[deviceID2-300].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                        }
                        else
                        {
                            cout<<"\n Invalid device Id entered for device 2\n";
                        }
                    }
                    else if(deviceID1>=300 && deviceID1<bridgeDeviceId)
                    {
                        if(deviceID2<endDeviceId)
                        {
                            objBridge[deviceID1-300].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId); 
                            obj[deviceID2].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);      
                        }
                        else if (deviceID2>=100 && deviceID2<hubDeviceId)
                        {
                            objBridge[deviceID1-300].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                            objHub[deviceID2-100].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                        }
                        else if(deviceID2>=200 && deviceID2<switchDeviceId)
                        {
                            objBridge[deviceID1-300].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                            objSwitch[deviceID2-200].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                        }
                        else if (deviceID2>=300 && deviceID2<bridgeDeviceId)
                        {
                            objBridge[deviceID1-300].setConnection(deviceID2,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                            objBridge[deviceID2-300].setConnection(deviceID1,endDeviceId, hubDeviceId, switchDeviceId, bridgeDeviceId);
                        }
                        else
                        {
                            cout<<"\n Invalid device Id entered for device 2\n";
                        }
                    }
                    else
                    {
                        cout<<"\n Invalid device Id entered for device 1\n";
                    }
                    
                }
                else if(choice == 2)
                {
                    break;
                }
                else
                {
                    cout<<" Invalid choice.....Please try again\n";
                }
            }
            
                
        }
        else if(choice == 6)
        {
            cout<<"\n--------- DATA TRANSFER -------------\n";
            while(true)
            {
                cout<<"\n 1.Start Data Transfer \n";
                cout<<"\n 2.Exit\n";
                cout<<" Enter your choice : ";
                cin>>choice;
                if(choice == 1)
                {
                    noBroadcasts = 0;
                    cout<<"\n Source end Device Id : ";
                    cin>>deviceID1;
                    cout<<"\n Destination end Device Id : ";
                    cin>>deviceID2;
                    if(deviceID1>=endDeviceId || deviceID2>=endDeviceId)
                    {
                        cout<<"\n Invalid Device Id Entered\n";
                    }
                    else
                    {
                        if(obj[deviceID1].getConnection() == deviceID2)
                        {
                            cout<<"\n .........Sending Message from "<<obj[deviceID1].getDisplayName()<<" to "<<obj[deviceID2].getDisplayName()<<"\n";
                            cout<<"\n..........Message received by destination device : "<<obj[deviceID2].getDisplayName()<<"\n";
                        }
                        else
                        {
                            bool flag = 0,switchDetect = 0,lastdeviceHub = 0,lastDeviceSwitch = 0;
                            flowControl = 0,packets = 0, seqBits = 0,probability = 0;
                            persistance = 0;
                            path temp1;
                            path temp2;
                            queue<path> route;

                            intermediateID = obj[deviceID1].getConnection();
                            temp1.source = deviceID1;
                            temp1.intermediate = intermediateID;
                            temp1.destination = deviceID2;
                            if(intermediateID>=100 && intermediateID<hubDeviceId)
                            {
                                cout<<"\n.......>>Sending Message to Intermediate Device "<<objHub[intermediateID-100].getDisplayName()<<"\n";
                            }
                            else if(intermediateID>=200 && intermediateID<switchDeviceId)
                            {
                                cout<<"\n.......>>Sending Message to Intermediate Device "<<objSwitch[intermediateID-200].getDisplayName()<<"\n";
                            }
                            
                            temp1.source = deviceID1;
                            temp1.intermediate = intermediateID;
                            temp1.destination = deviceID2;
                            route.push(temp1);
                            // cout<<"\n\n"<<route.size()<<"\n";
                            // temp2 = route.front();
                           // cout<<"\n"<<temp2.source<<" "<<temp2.intermediate<<"\n";
                            while(flag!=1 && !route.empty())
                            {
                                temp2 = route.front();                               
                                intermediateID = temp2.intermediate;
                                
                                if(intermediateID>=200 && intermediateID<switchDeviceId && switchDetect == 0)
                                {
                                    cout<<"\n .........Switch detected in the network..........\n";
                                    
                                    srand(time(0));
                                    cout<<"\n ------ ACCESS CONTROL -------- ";
                                    
                                    accessControl(deviceID1,endDeviceId);
                                    cout<<"\n TOKEN is CAPTURED by PC"<<deviceID1<<" now start data transfer...\n";
                                    cout<<"\n FLOW CONTROL-- STOP N WAIT \n";
                                    
                                    cout << " Enter the Number Of Packets : ";
                                    cin >> packets;
                                    
                                    cout<<" Enter the persistence of device(double value) : ";
                                    cin>>persistance;
                                    probability = persistance*100;
                                    switchDetect = 1;
                                } 
                                else if(intermediateID>=100 && intermediateID<hubDeviceId)
                                {
                                    route.pop();
                                    vector<int> tempConnections=objHub[intermediateID-100].getConnections();
                                    for(int i=0;i<tempConnections.size();i++)
                                    {
                                        if(tempConnections[i] == temp2.source);
                                        else if(tempConnections[i] == temp2.destination)
                                        {
                                            noBroadcasts++;
                                            lastdeviceHub = 1;
                                            flag=1;
                                        }
                                        else if(tempConnections[i] < endDeviceId)
                                        {
                                            noBroadcasts++;
                                            cout<<"\n ...Sending Message to device : "<<obj[tempConnections[i]].getDisplayName()<<" using : "<<objHub[intermediateID-100].getDisplayName();
                                            cout<<"\n X.....Discard Message.....X\n";
                                        }
                                        else if(tempConnections[i]>endDeviceId)
                                        {
                                            noBroadcasts++;
                                            if(tempConnections[i]<hubDeviceId && tempConnections[i]>=100)
                                            {
                                                cout<<"\n ...>>Sending Message to intermediate device : "<<objHub[tempConnections[i]-100].getDisplayName()<<" using : "<<objHub[intermediateID-100].getDisplayName()<<"\n"; 
                                            }
                                            else if(tempConnections[i]<switchDeviceId && tempConnections[i]>=200)  
                                            {
                                                cout<<"\n ...>>Sending Meassage to intermediate device : "<<objSwitch[tempConnections[i]-200].getDisplayName()<<" using : "<<objHub[intermediateID-100].getDisplayName();
                                            }
                                            temp1.source = intermediateID;
                                            temp1.intermediate = tempConnections[i];
                                            temp1.destination = deviceID2;
                                            route.push(temp1);
                                        }
                                    }
                                } 
                                //address learning of switch //
                                
                                else if(intermediateID>=200 && intermediateID<switchDeviceId && switchDetect == 1)
                                {
                                    route.pop();
                                    vector<int> tempConnections=objSwitch[intermediateID-200].getConnections();
                                    if(objSwitch[intermediateID-200].getAddressLearning() == 0)
                                    {
                                        objSwitch[intermediateID-200].setAddressLearning();
                                        for(int i=0;i<tempConnections.size();i++)
                                        {
                                            if(tempConnections[i] == temp2.source);
                                            else if(tempConnections[i] == temp2.destination)
                                            {
                                                noBroadcasts++;
                                                lastDeviceSwitch = 1;
                                                flag = 1;
                                            }
                                            else if(tempConnections[i] < endDeviceId)
                                            {
                                                noBroadcasts++;
                                                cout<<"\n ...Sending packets to device : "<<obj[tempConnections[i]].getDisplayName()<<" using : "<<objSwitch[intermediateID-200].getDisplayName();
                                                cout<<"\n X.....Packets Discarded.....X\n";
                                            }
                                            else if(tempConnections[i]>endDeviceId)
                                            {
                                                noBroadcasts++;
                                                if(tempConnections[i]<hubDeviceId && tempConnections[i]>=100)
                                                {
                                                    cout<<"\n ...>>Sending packets to intermediate device : "<<objHub[tempConnections[i]-100].getDisplayName()<<" using : "<<objSwitch[intermediateID-200].getDisplayName()<<"\n"; 
                                                }
                                                else if(tempConnections[i]<switchDeviceId && tempConnections[i]>=200)  
                                                {
                                                    cout<<"\n ...>>Sending packets to intermediate device : "<<objSwitch[tempConnections[i]-200].getDisplayName()<<"From : "<<objSwitch[intermediateID-200].getDisplayName()<<"\n";
                                                }
                                                else if(tempConnections[i]<bridgeDeviceId && tempConnections[i]>=300)
                                                {
                                                	cout<<"\n....>>Sending packets to intermediate device : "<<objBridge[tempConnections[i]-300].getDisplayName()<<"From : "<<objSwitch[intermediateID-200].getDisplayName();
												}
                                                temp1.source = intermediateID;
                                                temp1.intermediate = tempConnections[i];
                                                temp1.destination = deviceID2;
                                                route.push(temp1);
                                                
                                            }
                                        }
                                    } 
                                    else
                                    {
                                        for(int i=0;i<tempConnections.size();i++)
                                        {
                                            if(tempConnections[i] == temp2.source);
                                            else if(tempConnections[i] == temp2.destination)
                                            {
                                                lastDeviceSwitch = 1;
                                                flag=1;
                                                break;
                                            }
                                            else if(tempConnections[i] < endDeviceId);
                                            else if(tempConnections[i]>endDeviceId)
                                            {
                                                if(tempConnections[i]<hubDeviceId && tempConnections[i]>=100)
                                                {
                                                    noBroadcasts++;
                                                    cout<<"\n ...>>Sending Message to device : "<<objHub[tempConnections[i]-100].getDisplayName()<<"From : "<<objHub[intermediateID-100].getDisplayName()<<"\n"; 
                                                }
                                                else if(tempConnections[i]<switchDeviceId && tempConnections[i]>=200)  
                                                {
                                                    noBroadcasts++;
                                                    cout<<"\n ...Sending Meassage to device : "<<objSwitch[tempConnections[i]-200].getDisplayName()<<"From : "<<objHub[intermediateID-100].getDisplayName();
                                                }
                                                else if(tempConnections[i]<bridgeDeviceId && tempConnections[i]>=300)
                                                {
                                                	cout<<"\n....>>Sending packets to intermediate device : "<<objBridge[tempConnections[i]-300].getDisplayName()<<"From : "<<objSwitch[intermediateID-200].getDisplayName();
												}
                                                temp1.source = intermediateID;
                                                temp1.intermediate = tempConnections[i];
                                                temp1.destination = deviceID2;
                                                route.push(temp1);
                                            }
                                        }
                                    }
                                } 
                                else if(intermediateID>=300 && intermediateID<bridgeDeviceId)
                                {   
                                    route.pop();
                                    vector<int> tempConnections=objBridge[intermediateID-300].getConnections();
                                    
                                    for(int i=0;i<tempConnections.size();i++)
                                    {   
                                        if(tempConnections[i] == temp2.source);
                                        else if(tempConnections[i]>endDeviceId)
                                        {  
                                            noBroadcasts++;
                                            if(tempConnections[i]<hubDeviceId && tempConnections[i]>=100)
                                            {
                                                cout<<"\n ...>>Sending Message to intermediate device : "<<objHub[tempConnections[i]-100].getDisplayName()<<" using : "<<objBridge[intermediateID-300].getDisplayName()<<"\n"; 
                                            }
                                            else if(tempConnections[i]<switchDeviceId && tempConnections[i]>=200)  
                                            {    
                                            
                                                cout<<"\n ...>>Sending Meassage to intermediate device : "<<objSwitch[tempConnections[i]-200].getDisplayName()<<" using : "<<objBridge[intermediateID-300].getDisplayName();
                                            }
                                            temp1.source = intermediateID;
                                            temp1.intermediate = tempConnections[i];
                                            temp1.destination = deviceID2;
                                            route.push(temp1);
                                        }
                                    }
                                }  
                            }
                            if(flag == 1 && lastdeviceHub == 1) 
                            {

                                cout<<"\n ...Sending Message to device : "<<obj[deviceID2].getDisplayName()<<" using : "<<objHub[intermediateID-100].getDisplayName();
                                cout<<"\n Total no of Broadcasts : "<<noBroadcasts<<"\n";
                                cout<<"\n\n ........Message Received by destination device........"<<obj[deviceID2].getDisplayName()<<"\n";
                                cout<<"\n......Message transfer Complete..........\n";
                            }
                            else if(flag == 1 && lastDeviceSwitch == 1)
                            {

                                cout<<"\n ...Sending Packets to device : "<<obj[deviceID2].getDisplayName()<<" using : "<<objSwitch[intermediateID-200].getDisplayName();
                                
                                stopNwait_Sender(packets,probability);
                                
                                cout<<"\n Total no of Broadcasts : "<<noBroadcasts<<"\n";
                                cout<<"\n\n ......Mesage Received by destination device......"<<obj[deviceID2].getDisplayName()<<"\n";
                                cout<<"\n ......Message transfer Complete..........\n";
                            }
                            else if(flag==0 && route.empty())
                            {
                                cout<<"\n"<<route.size()<<"\n";
                                cout<<"\n\n X....Unable to send message as no direct OR indirect route possible......X\n";
                            }
                        }
                        
                    }
                }
                else if(choice == 2)
                {
                    break;
                }
                else
                {
                    cout<<" Invalid choice.....Please try again\n";
                }
            }

        }
        else if(choice == 7)
        {
            cout<<"\n--------- DISPLAYING ALL DEVICES -------------\n";
            displayAllEndDevices(obj);
            displayAllSwitches(objSwitch);
            displayAllbridges(objBridge);
            displayAllHubs(objHub);
        }
        else if(choice == 8)
        {
            cout<<"\n...............exiting.................\n";
            cout<<"\n============= THANK YOU ====================\n";  
            break;
        }
        else
        {
            cout<<"\n Invalid Input....Please try again\n";
        }
    }

}

