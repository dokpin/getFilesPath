#include <string>
#include <vector>
#include <filesystem>

void readImage(std::string directory, std::vector<std::string>& imageList)
{
	std::filesystem::path someDir(directory);
	std::filesystem::directory_iterator end_iter;
	std::vector<std::string> vc;

	for (std::filesystem::directory_iterator dir_iter(someDir); dir_iter != end_iter; ++dir_iter)
	{
		if (std::filesystem::is_regular_file(dir_iter->status()))
		{
			//printf("%s\n", dir_iter->path().filename() );
			if ((dir_iter->path().filename().generic_string().substr(dir_iter->path().filename().generic_string().length() - 3, 3) != "jpg")
				&& (dir_iter->path().filename().generic_string().substr(dir_iter->path().filename().generic_string().length() - 3, 3) != "png")
				&& (dir_iter->path().filename().generic_string().substr(dir_iter->path().filename().generic_string().length() - 3, 3) != "bmp")
				&& (dir_iter->path().filename().generic_string().substr(dir_iter->path().filename().generic_string().length() - 3, 3) != "tiff"))
				continue;
			//printf("%s\n", dir_iter->path().filename().generic_string().c_str());
			imageList.push_back(dir_iter->path().filename().generic_string());
		}
	}
	return;
}

int main()
{
	std::string directory = "C:/data/voc-train2017";
	std::vector<std::string> imageList;

	readImage(directory, imageList);

	for (int i = 0; i < imageList.size(); i++)
	{
		printf("%s\n", (directory + "/" + imageList[i]).c_str());
	}

	getchar();
}