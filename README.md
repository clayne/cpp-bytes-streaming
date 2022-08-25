# Bytes-Streaming Project

This is a simple "bytes-streaming" you can use for basically everything, it can be a loader or a software, this as been made for simple projects / for people that starts using C++, that means it's not protected at all from Reverse Engineering, or dumpers but still better than doing URLToDownloadFile.

### Credit

* [TheCruZ](https://blog.cr4.sh/) - For the streaming method that i took from his project [here](https://github.com/TheCruZ/kdmapper).

### Code

```cpp
bool utils::CreateFileFromMemory(const std::string& desired_file_path, const char* address, size_t size)
{
	std::ofstream file_ofstream(desired_file_path.c_str(), std::ios_base::out | std::ios_base::binary);

	if (!file_ofstream.write(address, size))
	{
		file_ofstream.close();
		return false;
	}

	file_ofstream.close();
	return true;
}
```

Also reading it from memory
```cpp
bool utils::ReadFileFromMemory(const std::string& file_path, std::vector<uint8_t>* out_buffer)
{
	std::ifstream file_ifstream(file_path, std::ios::binary);

	if (!file_ifstream)
		return false;

	out_buffer->assign((std::istreambuf_iterator<char>(file_ifstream)), std::istreambuf_iterator<char>());
	file_ifstream.close();

	return true;
}
```
