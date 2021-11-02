#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;
int main(){
	char x;
	do{
		int tt;
		cout<<"Press 1 to go to single person project\n";
		cout<<"press 2 to go to team project\n";
		cin>>tt;
		if(tt==1){
			int xx;
		cout<<"Press 1 to add a new Project\n";
		cout<<"Press 2 to add a new Member\n";
		cout<<"Press 3 to add a new Resource\n";
		cout<<"Press 4 to submit a project when completed\n";
		cout<<"Press 5 to see data of any project\n";
		cin>>xx;
		if(xx==1){
			string g;
			ifstream f("Single_Only_project.txt");
			int count22=0;
			while(getline(f,g)){
				count22++;
			}
			if(count22<=45){
				cin.ignore();
			string name;
			cout<<"Enter name of new project = ";
			getline(cin,name);
			ofstream file("Single_Project.txt",ios::app);
			file<<name<<"\n";
			file.close();
			ofstream filee("Single_Only_Project.txt",ios::app);
			filee<<name<<"\n";
			filee.close();
			ofstream wefile("Single_Project_name.txt",ios::app);
			wefile<<name<<"\n";
			wefile.close();
			ofstream fil("Single_Project_resource.txt",ios::app);
			fil<<name<<"\n";
			fil.close();
			cout<<"Now select the members for this project"<<endl;
			char select;
			ofstream rrfile("Single_Project.txt",ios::app);
			
				ifstream rfile("Single_Member.txt");
				string line,array[80]={};
				int i=0,ii;
				while(getline(rfile,line)){
					array[i]=line;
					cout<<"Press "<<i+1<<" to add "<<array[i]<<endl;
					i++;
				}
				rfile.clear();
				cin>>ii;
				ii--;
	      		rrfile<<array[ii]<<"\n";
		    	rrfile<<"/\n";
				rrfile.close();
				
					
			ofstream mm("Single_Project_resource.txt",ios::app);
			do{
				ifstream wrfile("Single_Resource.txt");
				string lin,resource[80]={};
				int i=0,ii,count=0;
				while(getline(wrfile,lin)){
					resource[i]=lin;
					count++;
					i++;
				}
				wrfile.close();
				if(count>0){
					for(int j=0;j<i;j++){
				     	cout<<"Press "<<j+1<<" to add "<<resource[j]<<endl;
			    	}
		    		cin>>ii;
			    	ii--;
			    	
			    	mm<<resource[ii]<<"\n";
			    	
			    	ofstream v("Single_Resource.txt");
			    	for(int j=0;j<i;j++){
			    		if(j!=ii){
			     			v<<resource[j]<<"\n";
			     			v.close();
			    		}
			    	}
			    	
			   	}
			    cout<<"Do you want to select another(Y/N) ";
			    cin>>select;
			    if(select!='Y' && select!='y'){
			    	mm<<"/\n";
			    	mm.close();		    	
				}
			}
			while(select=='y' || select=='Y');
			int day,year,month;
			cout<<"Enter day = ";
			cin>>day;
			cout<<"Enter month = ";
			cin>>month;
			cout<<"Enter year = ";
			cin>>year;
			ofstream mn("Single_Project_data.txt",ios::app);
			mn<<name<<"\t"<<"/"<<day<<"/"<<month<<"/"<<year<<"\n";
			mn.close();
			}
			else{
				cout<<"Present projects ="<<count22<<endl;
				cout<<"Total amount of projects is full\nSorry cannot add anymore projects\n";
			}
		}
		else if(xx==2){
			ifstream file("Single_Member.txt");
			string line;
			int count=0;
			while(getline(file,line)){
				count++;
			}
			if(count<=45){
				cin.ignore();
			string name;
			cout<<"Enter name of new Member = ";
			getline(cin,name);
			ofstream file("Single_Member.txt",ios::app);
			file<<name<<"\n";
			file.close();
			}
			else{
				cout<<"Total members present = "<<count<<endl;
				cout<<"Sorry cannot add more members\n";
			}
			
		}
		else if(xx==3){
			ifstream file("Single_Resource.txt");
			string line;
			int count=0;
			while(getline(file,line)){
				count++;
			}
			if(count<=45){
				cin.ignore();
			string name;
			cout<<"Enter name of new Resource = ";
			getline(cin,name);
			ofstream file("Single_Resource.txt",ios::app);
			file<<name<<"\n";
			file.close();
			}
			else{
				cout<<"Total Resources present = "<<count<<endl;
				cout<<"Sorry cannot add more resources\n";
			}
			
		}
		else if(xx==4){
			cin.ignore();
			string project,line,array[80]={};
			cout<<"Enter project name = ";
			getline(cin,project);
			int found=0;
			string date;
			ifstream f("Single_Project_name.txt");
			ifstream fil("Single_Project_data.txt");
			string kk,vv;
			while(getline(f,kk) && getline(fil,vv)){
				if(project.compare(kk)==0){
					date=vv;
					found=1;
					break;
				}
			}
			f.close();
			fil.close();
			ifstream file("Single_Project_data.txt");
			int count=0;
			while(getline(file,line)){
				array[count]=line;
				count++;
			}
			file.close();
			if(found==1){
				cout<<"Project found\n";
				string v="";
				int ii;
				for(ii=1;ii<date.length();ii++){
					int gg=date.length();
					if(date[gg-ii]!='/' && date[gg-ii]!=' '){
						string s(1,date[gg-ii]);
						v.append(s);
					}
					else if(date[gg-ii]=='/'){
						break;	
					}	
				}
				string ss="";
				for(int i=1;i<=v.length();i++){
					if(v[v.length()-i]!=' ' ){
						string s(1,v[v.length()-i]);
				   		ss.append(s);
					}	
				}
				int a;
				stringstream aa(ss);
				aa>>a;
				v="";
				for(int i=ii+1;i<date.length();i++){
					int gg=date.length();
					if(date[gg-i]!='/' && date[gg-i]!=' '){
						string s(1,date[gg-i]);
						v.append(s);
						ii++;
					}
					else if(date[gg-i]=='/'){
						ii++;
						break;	
					}	
				}
				ss="";
				for(int i=1;i<=v.length();i++){
					if(v[v.length()-i]!=' ' ){
						string s(1,v[v.length()-i]);
				   		ss.append(s);
					}	
				}
				int b;
				stringstream bb(ss);
				bb>>b;
				v="";
				for(int i=ii+1;i<date.length();i++){
					int gg=date.length();
					if(date[gg-i]!='/' && date[gg-i]!=' '){
						string s(1,date[gg-i]);
						v.append(s);
						ii++;
					}
					else if(date[gg-i]=='/'){
						ii++;
						break;	
					}	
				}
				ss="";
				for(int i=1;i<=v.length();i++){
					if(v[v.length()-i]!=' ' ){
						string s(1,v[v.length()-i]);
				   		ss.append(s);
					}	
				}
				int c;
				stringstream cc(ss);
				cc>>c;
				int day,year,month;
				cout<<"Enter day = ";
				cin>>day;
				cout<<"Enter month = ";
				cin>>month;
				cout<<"Enter year = ";
				cin>>year;
				if(year>=a && day>=c && day<=30 && day>0 && month>=b && month>0 && month<=12){
					string f[50]={},cc;
					int d=0;
					ifstream n("Single_Project_name.txt");
					while(getline(n,cc)){
						f[d]=cc;
						d++;
					}
					ofstream fiil("Single_Project_name.txt");
					for(int i=0;i<count;i++){
						if(project.compare(f[i])==0){
							fiil<<f[i]<<"\tDONE\n";
						}
						else{
							fiil<<f[i]<<"\n";
						}
					}
					fiil.close();
					ofstream file("Single_Project_data.txt");
					for(int i=0;i<count;i++){
						if(date.compare(array[i])==0){
							file<<array[i]<<"\t"<<day<<"/"<<month<<"/"<<year<<"\tDONE\n";
						}
						else{
							file<<array[i]<<"\n";
						}
					}
					file.close();
					ifstream read("Single_Project_resource.txt");
					string reading,readed[80]={};
					int t=0;
					while(getline(read,reading)){
						readed[t]=reading;
						t++;
					}
					read.close();
					int foundd=0;
					for(int i=0;i<t;i++){
						
						if(project.compare(readed[i])==0){
							ofstream filee("Single_Resource.txt",ios::app);
							for(int v=i+1;v<t;v++){
								if(readed[v].compare("/")!=0){
									filee<<readed[v]<<"\n";
								}
								else if(readed[v].compare("/")==0){
									filee.close();
									foundd=1;
									break;
								}
							}
		                }
		                if(foundd==1){
							break;
						}
					}
				}
				else{
					cout<<"Entered date is invalid"<<endl;
				}
					
			}
			else{
				cout<<"No such project"<<endl;
			}
			
		}
		else if(xx==5){
			cin.ignore();
			string project;
			cout<<"Enter project name = ";
			getline(cin,project);
			string data[80]={},line,lines;
			cout<<"Project name\tdate of submission\tDelivered date\tstatus"<<endl;
			ifstream file("Single_Only_Project.txt");
			ifstream rfile("Single_Project_data.txt");
			int p=0,found=0;
			while(getline(file,line) && getline(rfile,lines)){
				data[p]=line;
				if(data[p].compare(project)==0){
					found=1;
					cout<<lines<<endl;
				}
				
				p++;
			}
			file.close();
			if(found==1){
				ifstream file1("Single_Project.txt");
				int count1=0;
				string line1;
				while(getline(file1,line1)){
					data[count1]=line1;
					count1++;
				}
				file1.close();
				int l=0,found1=0;
				for(int i=0;i<count1;i++){
					if(project.compare(data[i])==0){
						
						for(int v=i+1;v<count1;v++){
							if(data[v].compare("/")!=0){
								cout<<"Member number "<<l+1<<" = "<<data[v]<<endl;
								l++;
								
							}
							else if(data[v].compare("/")==0){
								found1=1;
								break;
							}	
						}
					}
					if(found1==1){
						break;
					}
				}
				ifstream file2("Single_Project_resource.txt");
				int count2=0;
				string line2,data1[80]={};
				while(getline(file2,line2)){
					data1[count2]=line2;
					count2++;
				}
				file2.close();
				l=0,found1=0;
				for(int i=0;i<count2;i++){
					if(project.compare(data1[i])==0){
						for(int v=i+1;v<count2;v++){
							if(data1[v].compare("/")!=0){
								cout<<"Resource number "<<l+1<<" = "<<data1[v]<<endl;
								l++;
							}
							else if(data1[v].compare("/")==0){
								found1=1;
								break;
							}	
						}
					}
					if(found1==1){
						break;
					}
				}
			}
			else{
				cout<<"Invalid entry"<<endl;
			}
			
		}
		else{
			cout<<"Invalid entry"<<endl;
		}
		cout<<"Do you want to see project reports again(Y/N) ";
		cin>>x;
		}
		else if(tt==2){
			int xx;
		cout<<"Press 1 to add a new Project\n";
		cout<<"Press 2 to add a new Member\n";
		cout<<"Press 3 to add a new Resource\n";
		cout<<"Press 4 to submit a project when completed\n";
		cout<<"Press 5 to see data of any project\n";
		cin>>xx;
		if(xx==1){
			string g;
			ifstream f("Only_project.txt");
			int count22=0;
			while(getline(f,g)){
				count22++;
			}
			if(count22<=45){
				cin.ignore();
			string name;
			cout<<"Enter name of new project = ";
			getline(cin,name);
			ofstream file("Project.txt",ios::app);
			file<<name<<"\n";
			file.close();
			ofstream filee("Only_Project.txt",ios::app);
			filee<<name<<"\n";
			filee.close();
			ofstream wefile("Project_name.txt",ios::app);
			wefile<<name<<"\n";
			wefile.close();
			ofstream fil("Project_resource.txt",ios::app);
			fil<<name<<"\n";
			fil.close();
			cout<<"Now select the members for this project"<<endl;
			char select;
			ofstream rrfile("Project.txt",ios::app);
			do{
				ifstream rfile("Member.txt");
				string line,array[150]={};
				int i=0,ii;
				while(getline(rfile,line)){
					array[i]=line;
					cout<<"Press "<<i+1<<" to add "<<array[i]<<endl;
					i++;
				}
				rfile.clear();
				cin>>ii;
				ii--;
	      		rrfile<<array[ii]<<"\n";
		    	
				cout<<"Do you want to select another(Y/N) ";
				cin>>select;
				if(select!='Y' && select!='y'){
					rrfile<<"/\n";
					rrfile.close();
				}
			}
			while(select=='y' || select=='Y');
			ofstream mm("Project_resource.txt",ios::app);
			do{
				ifstream wrfile("Resource.txt");
				string lin,resource[150]={};
				int i=0,ii,count=0;
				while(getline(wrfile,lin)){
					resource[i]=lin;
					count++;
					i++;
				}
				wrfile.close();
				if(count>0){
					for(int j=0;j<i;j++){
				     	cout<<"Press "<<j+1<<" to add "<<resource[j]<<endl;
			    	}
		    		cin>>ii;
			    	ii--;
			    	
			    	mm<<resource[ii]<<"\n";
			    	
			    	ofstream v("Resource.txt");
			    	for(int j=0;j<i;j++){
			    		if(j!=ii){
			     			v<<resource[j]<<"\n";
			     			v.close();
			    		}
			    	}
			    	
			   	}
			    cout<<"Do you want to select another(Y/N) ";
			    cin>>select;
			    if(select!='Y' && select!='y'){
			    	mm<<"/\n";
			    	mm.close();		    	
				}
			}
			while(select=='y' || select=='Y');
			int day,year,month;
			cout<<"Enter day = ";
			cin>>day;
			cout<<"Enter month = ";
			cin>>month;
			cout<<"Enter year = ";
			cin>>year;
			ofstream mn("Project_data.txt",ios::app);
			mn<<name<<"\t"<<"/"<<day<<"/"<<month<<"/"<<year<<"\n";
			mn.close();
			}
			else{
				cout<<"Present projects ="<<count22<<endl;
				cout<<"Total amount of projects is full\nSorry cannot add anymore projects\n";
			}
		}
		else if(xx==2){
			ifstream file("Member.txt");
			string line;
			int count=0;
			while(getline(file,line)){
				count++;
			}
			if(count<=45){
				cin.ignore();
			string name;
			cout<<"Enter name of new Member = ";
			getline(cin,name);
			ofstream file("Member.txt",ios::app);
			file<<name<<"\n";
			file.close();
			}
			else{
				cout<<"Total members present = "<<count<<endl;
				cout<<"Sorry cannot add more members\n";
			}
			
		}
		else if(xx==3){
			ifstream file("Resource.txt");
			string line;
			int count=0;
			while(getline(file,line)){
				count++;
			}
			if(count<=45){
				cin.ignore();
			string name;
			cout<<"Enter name of new Resource = ";
			getline(cin,name);
			ofstream file("Resource.txt",ios::app);
			file<<name<<"\n";
			file.close();
			}
			else{
				cout<<"Total Resources present = "<<count<<endl;
				cout<<"Sorry cannot add more resources\n";
			}
			
		}
		else if(xx==4){
			cin.ignore();
			string project,line,array[150]={};
			cout<<"Enter project name = ";
			getline(cin,project);
			int found=0;
			string date;
			ifstream f("Project_name.txt");
			ifstream fil("Project_data.txt");
			string kk,vv;
			while(getline(f,kk) && getline(fil,vv)){
				if(project.compare(kk)==0){
					date=vv;
					found=1;
					break;
				}
			}
			f.close();
			fil.close();
			ifstream file("Project_data.txt");
			int count=0;
			while(getline(file,line)){
				array[count]=line;
				count++;
			}
			file.close();
			if(found==1){
				cout<<"Project found\n";
				string v="";
				int ii;
				for(ii=1;ii<date.length();ii++){
					int gg=date.length();
					if(date[gg-ii]!='/' && date[gg-ii]!=' '){
						string s(1,date[gg-ii]);
						v.append(s);
					}
					else if(date[gg-ii]=='/'){
						break;	
					}	
				}
				string ss="";
				for(int i=1;i<=v.length();i++){
					if(v[v.length()-i]!=' ' ){
						string s(1,v[v.length()-i]);
				   		ss.append(s);
					}	
				}
				int a;
				stringstream aa(ss);
				aa>>a;
				v="";
				for(int i=ii+1;i<date.length();i++){
					int gg=date.length();
					if(date[gg-i]!='/' && date[gg-i]!=' '){
						string s(1,date[gg-i]);
						v.append(s);
						ii++;
					}
					else if(date[gg-i]=='/'){
						ii++;
						break;	
					}	
				}
				ss="";
				for(int i=1;i<=v.length();i++){
					if(v[v.length()-i]!=' ' ){
						string s(1,v[v.length()-i]);
				   		ss.append(s);
					}	
				}
				int b;
				stringstream bb(ss);
				bb>>b;
				v="";
				for(int i=ii+1;i<date.length();i++){
					int gg=date.length();
					if(date[gg-i]!='/' && date[gg-i]!=' '){
						string s(1,date[gg-i]);
						v.append(s);
						ii++;
					}
					else if(date[gg-i]=='/'){
						ii++;
						break;	
					}	
				}
				ss="";
				for(int i=1;i<=v.length();i++){
					if(v[v.length()-i]!=' ' ){
						string s(1,v[v.length()-i]);
				   		ss.append(s);
					}	
				}
				int c;
				stringstream cc(ss);
				cc>>c;
				int day,year,month;
				cout<<"Enter day = ";
				cin>>day;
				cout<<"Enter month = ";
				cin>>month;
				cout<<"Enter year = ";
				cin>>year;
				if(year>=a && day>=c && day<=30 && day>0 && month>=b && month>0 && month<=12){
					string f[150]={},cc;
					int d=0;
					ifstream n("Project_name.txt");
					while(getline(n,cc)){
						f[d]=cc;
						d++;
					}
					ofstream fiil("Project_name.txt");
					for(int i=0;i<count;i++){
						if(project.compare(f[i])==0){
							fiil<<f[i]<<"\tDONE\n";
						}
						else{
							fiil<<f[i]<<"\n";
						}
					}
					fiil.close();
					ofstream file("Project_data.txt");
					for(int i=0;i<count;i++){
						if(date.compare(array[i])==0){
							file<<array[i]<<"\t"<<day<<"/"<<month<<"/"<<year<<"\tDONE\n";
						}
						else{
							file<<array[i]<<"\n";
						}
					}
					file.close();
					ifstream read("Project_resource.txt");
					string reading,readed[150]={};
					int t=0;
					while(getline(read,reading)){
						readed[t]=reading;
						t++;
					}
					read.close();
					int foundd=0;
					for(int i=0;i<t;i++){
						
						if(project.compare(readed[i])==0){
							ofstream filee("Resource.txt",ios::app);
							for(int v=i+1;v<t;v++){
								if(readed[v].compare("/")!=0){
									filee<<readed[v]<<"\n";
								}
								else if(readed[v].compare("/")==0){
									filee.close();
									foundd=1;
									break;
								}
							}
		                }
		                if(foundd==1){
							break;
						}
					}
				}
				else{
					cout<<"Entered date is invalid"<<endl;
				}
					
			}
			else{
				cout<<"No such project"<<endl;
			}
			
		}
		else if(xx==5){
			cin.ignore();
			string project;
			cout<<"Enter project name = ";
			getline(cin,project);
			string data[150]={},line,lines;
			cout<<"Project name\tdate of submission\tDelivered date\tstatus"<<endl;
			ifstream file("Only_Project.txt");
			ifstream rfile("Project_data.txt");
			int p=0,found=0;
			while(getline(file,line) && getline(rfile,lines)){
				data[p]=line;
				if(data[p].compare(project)==0){
					found=1;
					cout<<lines<<endl;
				}
				
				p++;
			}
			file.close();
			if(found==1){
				ifstream file1("Project.txt");
				int count1=0;
				string line1;
				while(getline(file1,line1)){
					data[count1]=line1;
					count1++;
				}
				file1.close();
				int l=0,found1=0;
				for(int i=0;i<count1;i++){
					if(project.compare(data[i])==0){
						
						for(int v=i+1;v<count1;v++){
							if(data[v].compare("/")!=0){
								cout<<"Member number "<<l+1<<" = "<<data[v]<<endl;
								l++;
							}
							else if(data[v].compare("/")==0){
								found1=1;
								break;
							}	
						}
					}
					if(found1==1){
						break;
					}
				}
				ifstream file2("Project_resource.txt");
				int count2=0;
				string line2,data1[150]={};
				while(getline(file2,line2)){
					data1[count2]=line2;
					count2++;
				}
				file2.close();
				l=0,found1=0;
				for(int i=0;i<count2;i++){
					if(project.compare(data1[i])==0){
						for(int v=i+1;v<count2;v++){
							if(data1[v].compare("/")!=0){
								cout<<"Resource number "<<l+1<<" = "<<data1[v]<<endl;
								l++;
							}
							else if(data1[v].compare("/")==0){
								found1=1;
								break;
							}	
						}
					}
					if(found1==1){
						break;
					}
				}
			}
			else{
				cout<<"Invalid entry"<<endl;
			}
			
		}
		else{
			cout<<"Invalid entry"<<endl;
		}
		cout<<"Do you want to see project reports again(Y/N) ";
		cin>>x;
		}
		else{
			cout<<"Invalid entry"<<endl;
		}
	}
	while(x=='Y' || x=='y');
}





