#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <thread>

bool loadImage(string inputName, Mat &image)
{
  bool from_net;
  from_net = true;


  if (inputName.find("http") != string::npos)
    {
      string URL;
      URL = inputName;
      if (inputName.find("\"") == 0)
        {
           URL = inputName.substr(1,inputName.length()-2);
        }

  std::ostringstream stream;

  curl_writer writer(stream);
  // Pass it to the easy constructor and watch the content returned in that file!
  curl_easy easy(writer);

  // Add some option to the easy handle
  easy.add(curl_pair<CURLoption,string>(CURLOPT_URL,URL));
  easy.add(curl_pair<CURLoption,long>(CURLOPT_FOLLOWLOCATION,1L));

  try {
    easy.perform();
  } catch (curl_easy_exception error) {
    // If you want to get the entire error stack we can do:
    vector<pair<string,string>> errors = error.what();
    // Otherwise we could print the stack like this:
    error.print_traceback();
  }
  string output = stream.str(); // convert the stream into a string
  if (output.find("404 Not Found") != string::npos)
    from_net = false;
  else
  {
      vector<char> data = std::vector<char>( output.begin(), output.end() ); //convert string into a vector 
  if (data.size() > 0)
    {
      Mat data_mat = Mat(data); // create the cv::Mat datatype from the vector
      image = imdecode(data_mat,-1); //read an image from memory buffer
      if(image.rows == 0 || image.cols == 0)
    from_net = false;
    }
  else
    from_net = false;
    }
}
  else
    {
      image = imread( inputName, 1 );
      if (image.total() < 1)         
        from_net = false;   
    }
  return from_net;
}
int main()
{
	//auto time = std::chrono::system_clock::now();
	//std::time_t _time = std::chrono::system_clock::to_time_t(time);
	//std::cout << "Date: " << std::ctime(&_time) << endl;
	//string s  = "LOAy";
	//std::transform(s.begin(), s.end(),s.begin(), ::toupper);
	//dye::blue("Hfg");
	//cout << dye::light_red_on_grey("College Entery");
	//cout << "start" << endl;
    //this_thread::sleep_for (chrono::seconds(1));  // for C++14 users you can simply write 1s to denote 1 second
    //Sleep(2000);
	/*char ch = getch();
	if (ch == 0)
			return 0;
	ch = toupper(ch);
	//char ch = getch();
	cout << ch << endl;
	cout << "STREEM            DEGREE-I          DEGREE-II";*/
	gotoxy(50, 2);
	cout << dye::aqua_on_bright_white("Loay Terek Mostafa");
}
