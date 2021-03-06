#pragma once

#include <sstream>
#include <vector>

namespace Receiver
{
	namespace ReceiverLib
	{
		struct Column
		{
			std::string _columnLabel;
			std::vector<std::string> _columnData;
		};

		void splitColumnData(std::stringstream& data, Column& column);
		void checkForDelimiter(std::stringstream&, Column& column);

		class DataStreamParser
		{
		private:
			std::vector<Column> _columns;
			std::string _filteredData;
		public:
			DataStreamParser() = default;
			explicit DataStreamParser(std::string& data) : _filteredData(data) {}
			explicit DataStreamParser(DataStreamParser& data_stream_parser) : _columns(data_stream_parser._columns), _filteredData(data_stream_parser._filteredData) {}
			void handleParsedData(std::string&);
		    std::vector<Column>& getColumns();
			int updateColumnLabels(std::string&);
		};
	}
}
