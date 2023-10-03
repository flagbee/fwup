
# Practical **Embedded Firmware Upgrade System**

## Overview
&emsp;Devices based on embedded software require maintenance in the user's environment. To facilitate this, firmware download functionality is typically supported through a dedicated download device. Additionally, for users without dedicated downloaders and to enhance usability, firmware download functionality through universal interfaces like UART and Ethernet is provided. STM, in its application note, introduces firmware download using universal interfaces as "In-Application Programming (IAP)" and aims to provide requirements and implementation methods, along with examples using the STM32F board.   
<p align="center" width="100%">
    <img width="50%" src="https://github.com/flagbee/fwup/assets/32917812/a9e984f0-4032-481a-8167-c9e6c65761dc"> 
</p>


## Basic Firmware Upgrade Functionality - IAP Summary

1. Flash Partition
    * The IAP functionality is divided into two parts. The IAP driver code and the user application code for upgrades.
    * Upon RESET, the device typically boots into the user application area, but it can also boot into the IAP code area upon specific user input.
      <p align="center" width="100%">
          <img width="80%" src="https://github.com/flagbee/fwup/assets/32917812/11e4719b-1a27-4d93-bb01-3395b5b2e697"> 
      </p>
2. System Configuration
    * Device
        1. The device where firmware upgrades are performed.
    * UI (Teraterm)
        * Connected to the device via UART, providing a text-based UI.
3. Operation Flow
    * Upon specific user input, the IAP Driver is executed to enter firmware upgrade mode.
    * Users can select and perform firmware upgrades through the UI.
4. References
    * **[STM32 In-Application Programming (IAP) using the USART - Application Note](https://www.st.com/resource/en/application_note/an4657-stm32-inapplication-programming-iap-using-the-usart-stmicroelectronics.pdf)**
    * **[USART Protocol used in the STM32 Bootloader - Application Note](https://www.st.com/resource/en/application_note/an3155-usart-protocol-used-in-the-stm32-bootloader-stmicroelectronics.pdf)**
    
## Practical Implementation Approach
&ensp;In addition to the STM IAP Application note, this document introduces enhancements for various quality characteristics.

### Requirements
1.  Reliability Improvement
    1. Firmware Data Integrity Verification
        *   During the upgrade process, firmware upgrades should be interrupted and entered into a recoverable state in the following situations:
            1.  Attempting to upgrade with unsigned or invliad firmware files.
            2.  Using corrupted firmware files for upgrades.
            3.  Issues during firmware file transmission.
            4.  Problems during firmware writing.        
    2. Pre-boot Inspection - Secure Boot
    3. Memory Protection
        * The bootloader area, responsible for firmware upgrades and recovery, should be protected from intrusion by the MCU's internal ROM or equivalent.
        * Protection Rules Example
            1. When the bootloader runs:
                1. Bootloader area: Execute.
                2. Application area: Execute/Write/Read.
            2. When the application runs:
                1. Bootloader area: No Read, No Write, No Execute.
                2. Application area: Execute/Read allowed, No Write.
    4. Recovery Mechanism
        * In situations where the application area cannot be executed for several reasons, an automatic firmware upgrade capability should be available for recovery.
        * Alternatively, the use of a secondary partition can be employed to ensure that the last successfully executed application is run.
3.  Usability Improvement
    1. Bootloader and Application Mode Switching
        * During the execution of the application, firmware upgrade may be required. The system should be able to transition into a state where only the bootloader is running during the upgrade process or return to the application after upgrading is complete.
    2. Additional Firmware Data Information
        * Firmware data should include information such as version and model distinctions to enable various policies and purposes, including verifying that the firmware data matches the device.
        * These pieces of information can be used for:
            1. Preventing downgrades - security policy
            2. Model type differentiation
            3. Checking for backward compatibility
    3. Firmware Upgrade Status Checking
        1. The firmware upgrade procedure typically involves transmission, data integrity verification, flashing, and flashing validation processes, which can take seconds to minutes and may encounter various exceptions. Hence, a mechanism is required to track progress, status, and errors.
4.  Compatibility Enhancement
    1. The firmware file format will be based on Intel HEX.
    2. Ethernet-based communication will be used instead of UART for data transmission.

### Design
1. Flash Partition
    1. Bootloader
    2. Supplementing Partition Design
        1. Apart from the bootloader and application areas, there is a need for storage space to hold partition information, log data, serial numbers, and other device-related information.
         <p align="center" width="100%">
          <img width="33%" src="https://github.com/flagbee/fwup/assets/32917812/d71cc1e5-c14e-4e16-a47d-b3d4dd54b048"> 
         </p>
        2. Device Information Area : the boot information should be kept such as 'current boot partition', 'latest boot status', ...
        3. Secondary Application Area : This area can be used for the recovery mechanism.
2. System
    * A firmware upgrade system consists of an embedded system that is the target for the upgrade and a client that requests the upgrade to be performed.
      <p align="center" width="100%">
       <img width="80%" src="https://github.com/flagbee/fwup/assets/32917812/37aabcb1-96b9-4129-ae5d-3dc719410040">      
      </p>       
    * Components
        * Embedded system
            * Boot loader
            * Application
            * Interface      
        * Client
            * GUI
            * Interface
     
4. Operation Flow
    1. Upgrading sequence       
    3. Boot sequence and firmware upgrading(Embedded system) 
      <p align="center" width="100%">
       <img width="100%" src="https://github.com/flagbee/fwup/assets/32917812/3a81f034-4aa9-46da-8437-be2bb4dbd21c"> 
      </p>      
5. Firmware Structure
    1. Header: Version, Information for Secure Boot
    2. Data: Application Firmware

### Implementations
   1. Development environment
      <p align="center" width="100%">
       <img width="80%" src="https://github.com/flagbee/fwup/assets/32917812/1653e700-d50d-4c55-83ca-78d8443b16d8">      
      </p>      
   2. Deliverable
       1. STM32 Project : Bootloader
       2. STM32 Project : Application
       3. CPP library : interfaces
       4. Windows application : firmware upgrading tool   

### Miscellaneous
   1. Memory must be cleared when jumping from the bootloader to the application area.
  
.
