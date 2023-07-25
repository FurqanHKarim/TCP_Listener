#include "file_handler.h"




void file_handler:: write_file(Data_recieved &current) {
	this->reservoir.write(current.TXT, current.lenght_txt);
	this->reservoir.write("\0\n\n\n\n", 5);

}


void file_handler:: open_file(string filename) {
	this->reservoir.open(filename, ios::app);


}
void file_handler:: confirm_file_open() {
	
	if (!this->reservoir.is_open()) {
		cout << "File Opening Failed: ";
		return;
	}
}
void file_handler:: file_close() {
	this->reservoir.close();
};
