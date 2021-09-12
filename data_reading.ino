/*

    Copyright (C) 2017 Libelium Comunicaciones Distribuidas S.L.
   http://www.libelium.com

    By using it you accept the MySignals Terms and Conditions.
    You can find them at: http://libelium.com/legal

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Version:           0.1
    Design:            David Gascon
    Implementation:    Luis Martin / Victor Boria
*/

#include <MySignals.h>
#include "Wire.h"
#include "SPI.h" 

void setup() 
{
  Serial.begin(115200);
  MySignals.begin(); 
  
  MySignals.initSensorUART();
  
  MySignals.enableSensorUART(ADC_ECG);
  delay(1000);
  
//  MySignals.enableSensorUART(BLOODPRESSURE);
//  delay(1000);
  
  MySignals.enableSensorUART(ADC_AIRFLOW);
  delay(1000);
  
  MySignals.enableSensorUART(ADC_EMG);
  delay(1000);
    // SPM flag initialization
  MySignals.ECGFlagBPM = 1;
  // Interrupt every 6 ms
  MySignals.initInterrupt(6);
}

void loop() 
{
 /****************** This is the ECG data acquisition part *********************************/

  float ECG = MySignals.getECG(VOLTAGE);
  Serial.println(ECG, 2);


    /****************** This is the EMG data acquisition part *********************************/
  float EMG = MySignals.getEMG(VOLTAGE);
  Serial.println(EMG, 2);

 /****************** This is the ECG BPM data acquisition part *********************************/

 
//  Serial.print("BPM rate = ");
  float BPM=MySignals.ECGDataBPMBalanced;
  Serial.println(BPM);
  
  /****************** This is the airflow data acquisition part *********************************/
  
  float air = MySignals.getAirflow(VOLTAGE);   
  Serial.println(air, 2);


 delay(10); 
}
