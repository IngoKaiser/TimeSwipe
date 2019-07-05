//ADC-DAC mux:

#pragma once

enum class typeADgain: int {gainX1=1, gainX2, gainX4, gainX8};
enum class typeDACmode : int {ExtDACs=0, SamAndExtDACs};

class CADmux
{
protected:
        typeADgain m_CurGain;
        typeDACmode m_CurDACmode;
        bool       m_UBRVoltage;
        bool       m_bADmesEnabled;  //18.06.2019

public:
	CADmux();
	
	void EnableADmes(bool how);
        bool IsADmesEnabled(){return m_bADmesEnabled; } //18.06.2019
	
	void SetGain(typeADgain gain);
        typeADgain GetGain(){ return m_CurGain; }
        void SetDACmode(typeDACmode mode);
        void SetUBRvoltage(bool how);
        bool GetUBRVoltage(){ return m_UBRVoltage; }

        //converter:
         void setDACsw(int mode){ SetDACmode(mode ? typeDACmode::SamAndExtDACs : typeDACmode::ExtDACs); }
         int getDACsw(){ return static_cast<int>(m_CurDACmode); }

};
