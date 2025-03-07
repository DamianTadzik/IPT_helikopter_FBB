    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (bubu_01_P)
        ;%
            section.nData     = 56;
            section.data(56)  = dumData; %prealloc

                    ;% bubu_01_P.BandLimitedWhiteNoise_Cov
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% bubu_01_P.BandLimitedWhiteNoise_seed
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% bubu_01_P.Reset_Value
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% bubu_01_P.Normal_Value
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% bubu_01_P.AnalogInput_P1_Size
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% bubu_01_P.AnalogInput_P1
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 6;

                    ;% bubu_01_P.AnalogInput_P2_Size
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 7;

                    ;% bubu_01_P.AnalogInput_P2
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 9;

                    ;% bubu_01_P.AnalogInput_P3_Size
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 11;

                    ;% bubu_01_P.AnalogInput_P3
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 13;

                    ;% bubu_01_P.AnalogInput_P4_Size
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 15;

                    ;% bubu_01_P.AnalogInput_P4
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 17;

                    ;% bubu_01_P.ConverttoRPM_Gain
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 18;

                    ;% bubu_01_P.WhiteNoise_Mean
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 19;

                    ;% bubu_01_P.WhiteNoise_StdDev
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 20;

                    ;% bubu_01_P.Sat1_UpperSat
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 21;

                    ;% bubu_01_P.Sat1_LowerSat
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 22;

                    ;% bubu_01_P.Encoder_P1_Size
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 23;

                    ;% bubu_01_P.Encoder_P1
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 25;

                    ;% bubu_01_P.Encoder_P2_Size
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 26;

                    ;% bubu_01_P.Encoder_P2
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 28;

                    ;% bubu_01_P.Encoder1024PPR_Gain
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 29;

                    ;% bubu_01_P.Converttorad_Gain
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 31;

                    ;% bubu_01_P.Constant_Value
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 32;

                    ;% bubu_01_P.Sat_UpperSat
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 33;

                    ;% bubu_01_P.Sat_LowerSat
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 34;

                    ;% bubu_01_P.PWM_corr_Gain
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 35;

                    ;% bubu_01_P.PWM_corr1_Gain
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 36;

                    ;% bubu_01_P.Saturation_UpperSat
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 37;

                    ;% bubu_01_P.Saturation_LowerSat
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 38;

                    ;% bubu_01_P.PWM_P1_Size
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 39;

                    ;% bubu_01_P.PWM_P1
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 41;

                    ;% bubu_01_P.PWM_P2_Size
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 42;

                    ;% bubu_01_P.PWM_P2
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 44;

                    ;% bubu_01_P.ResetEncoder_P1_Size
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 45;

                    ;% bubu_01_P.ResetEncoder_P1
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 47;

                    ;% bubu_01_P.ResetEncoder_P2_Size
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 48;

                    ;% bubu_01_P.ResetEncoder_P2
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 50;

                    ;% bubu_01_P.BitstreamVersion_P1_Size
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 51;

                    ;% bubu_01_P.BitstreamVersion_P1
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 53;

                    ;% bubu_01_P.BitstreamVersion_P2_Size
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 54;

                    ;% bubu_01_P.BitstreamVersion_P2
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 56;

                    ;% bubu_01_P.ThermStatus_P1_Size
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 57;

                    ;% bubu_01_P.ThermStatus_P1
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 59;

                    ;% bubu_01_P.ThermStatus_P2_Size
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 60;

                    ;% bubu_01_P.ThermStatus_P2
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 62;

                    ;% bubu_01_P.PWMPrescalerSource_Value
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 63;

                    ;% bubu_01_P.PWMPrescaler_P1_Size
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 65;

                    ;% bubu_01_P.PWMPrescaler_P1
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 67;

                    ;% bubu_01_P.PWMPrescaler_P2_Size
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 68;

                    ;% bubu_01_P.PWMPrescaler_P2
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 70;

                    ;% bubu_01_P.ThermFlagSource_Value
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 71;

                    ;% bubu_01_P.ThermFlag_P1_Size
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 73;

                    ;% bubu_01_P.ThermFlag_P1
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 75;

                    ;% bubu_01_P.ThermFlag_P2_Size
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 76;

                    ;% bubu_01_P.ThermFlag_P2
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 78;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% bubu_01_P.ResetEncoders_CurrentSetting
                    section.data(1).logicalSrcIdx = 56;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (bubu_01_B)
        ;%
            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% bubu_01_B.AnalogInput
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% bubu_01_B.ConverttoRPM
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% bubu_01_B.Sat1
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% bubu_01_B.Encoder
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% bubu_01_B.Converttorad
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 7;

                    ;% bubu_01_B.ResetEncoders
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 9;

                    ;% bubu_01_B.Saturation
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 10;

                    ;% bubu_01_B.PWM
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 12;

                    ;% bubu_01_B.ResetEncoder
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 14;

                    ;% bubu_01_B.BitstreamVersion
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 16;

                    ;% bubu_01_B.ThermStatus
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 17;

                    ;% bubu_01_B.PWMPrescalerSource
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 19;

                    ;% bubu_01_B.PWMPrescaler
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 21;

                    ;% bubu_01_B.ThermFlagSource
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 23;

                    ;% bubu_01_B.ThermFlag
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 25;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (bubu_01_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% bubu_01_DW.NextOutput
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% bubu_01_DW.RPM_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% bubu_01_DW.Scope_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% bubu_01_DW.RandSeed
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 2082066111;
    targMap.checksum1 = 2911731541;
    targMap.checksum2 = 1824131142;
    targMap.checksum3 = 1065996129;

