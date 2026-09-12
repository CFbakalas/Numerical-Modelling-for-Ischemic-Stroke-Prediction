
# Introduction
This repository contains the files used to execute all heathy, occluded and reverse flow cases for the Numerical Methods for Ischemic Stroke Prediction thesis discussed Computational Fluid Dynamics Simulations. 

The following files are therefore attached: 
- ANSYS FLUENT Settings files for occluded cases, as defined per occluded arteriole
- ANSYS FLUENT Submission (.sub) files
- ANSYS FLUENT Journal (.jou) files
- ANSYS FLUENT Simulation Case (.cas) files

The files above therefore constitute full directory per case to be simulated. Instructions to further run each simulation are found below: 

# Files Upload
MobaXTerm was used as a custom terminal for use of the DELTA2 and CRESCENT HPC Clusters. The GUI on the LHS allows the user to upload or download case files without terminal commands. 
## Directory Construction

### General 
The settings, journal, case and UDF files should be added to the same directory. The same case file can be used with different settings files to load the occluded, healthy or reverse flow cases. 

### Journal File
For each case directory the FULL FILE path for: 
- Autosave
- Case file
- Settings file
- UDF file
- Data File
must be explicitly defined in the named section between the quotations ("") as seen in the journal file. Then, mesh selection and settings selection is done by replacing the desired settings and case file in the named section of the journal file. No changes have to be dine in the UDF file as the settings file sorts arteriole occlusion accordingly. 

## Submission File

Following the completion of the journal file changes alongside the correct directory setup, the ANSYS FLUENT submission file must be configured. It is suggested to run cases using: 
Fine Mesh: 
- 128 Cores
- 6 Hours
Medium Mesh:
- 64 Cores
- 3 Hours
Furthermore, the simulation name should be changed to the desired case for ease of identification. The exact name of the journal file must be finally stated. All instructions for the submission file configuration can be found within the submission file. 
# Software Requirements and Execution
## Version Requirements
All cases are compiled using ANSYS FLUENT 2025 R2. Settings and Journal file difference per ANSYS FLUENT version bind the use of the specific software version to avoid compiling error. 

## Case Execution
Case Execution was done using the CRESCENT High Performance Computing (HPC) Cluster. The following commands are executed using the SLURM cluster library: 
- qsub "submission file name": submit case to cluster
- qstat: check the queue times and queue state of each simulation
- qdel: delete case submitted

## Safety Measures
It is common that HPC simulations might require more time than allowed within the journal file. The HPC abruptly stops case execution once the time limit is passed resulting in either corrupted files or non usable data (.dat) files regardless of autosave definition in the journal file. To avoid this, the following actions must be taken: 
- Open live .trn console state using: 
	- Enter live simulation directory: cd *
	- View live update of simulation case: tail -f *
- If time is about to exceed:
	- Return to simulated case parent directory
	- Stop ANSYS FLUENT simulation: touch fluent.exit
- Therefore: 
	- Final data and case files (.dat, .cas respectively) are saved. 