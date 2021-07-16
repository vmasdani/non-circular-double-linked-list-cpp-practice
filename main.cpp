// Practice Implementation of Non-Circular Double LinkedList with object-oriented programming in C++

#include <iostream>
#include <memory>

class DLLNCData
{
private:
	std::string _name;
	std::string _student_id;
	std::string _value;

public:
	void set_name(std::string name)
	{
		_name = name;
	}

	std::string get_name()
	{
		return _name;
	}

	void set_student_id(std::string student_id)
	{
		_student_id = student_id;
	}

	std::string get_student_id()
	{
		return _student_id;
	}

	void set_value(std::string value)
	{
		_value = value;
	}

	std::string get_value()
	{
		return _value;
	}
};

class DLLNC
{
private:
	std::weak_ptr<DLLNCData> _data;
	std::weak_ptr<DLLNC> _next;
	std::weak_ptr<DLLNC> _prev;

public:
	void set_data(std::weak_ptr<DLLNCData> data)
	{
		_data = data;
	}

	void set_next(std::weak_ptr<DLLNC> next)
	{
		_next = next;
	}

	void set_prev(std::weak_ptr<DLLNC> prev)
	{
		_prev = prev;
	}

	void print_contents()
	{
		auto data_val = _data.lock().get();

		if (data_val)
		{
			std::cout << data_val->get_name() << std::endl;
		}
		else
		{
			std::cout << "data_val is null" << std::endl;
		}
	}

	void print_all(unsigned int index)
	{

		// Get data contents
		auto data_val = _data.lock().get();

		if (data_val)
		{
			std::cout << index << ". " << data_val->get_name() << " | NIM: " << data_val->get_student_id() << " | Nilai: " << data_val->get_value() << std::endl;
		}
		else
		{
			std::cout << "data_val is null" << std::endl;
		}

		// Get next
		auto next_data = _next.lock().get();

		if (next_data)
		{
			next_data->print_all(index + 1);
		}
		else
		{
			std::cout << "\nnext_data is NULL. Terminating recursion." << std::endl;
		}
	}

	void push_back()
	{
		// TODO: UNIMPLEMENTED
	}

	void push_front()
	{
		// TODO: UNIMPLEMENTED
	}

	void push_middle(unsigned int index)
	{
		// TODO: UNIMPLEMENTED
	}

	void delete_back()
	{
		// TODO: UNIMPLEMENTED
	}

	void delete_front()
	{
		// TODO: UNIMPLEMENTED
	}
};

int main()
{
	// ======== DECLARATIONS =======

	// DATA 6
	auto data_6_data = std::make_shared<DLLNCData>(DLLNCData());
	data_6_data->set_name("Bjork");
	data_6_data->set_student_id("8391928396");
	data_6_data->set_value("70");

	auto data_6 = std::make_shared<DLLNC>(DLLNC());
	data_6->set_data(data_6_data);

	// DATA 5
	auto data_5_data = std::make_shared<DLLNCData>(DLLNCData());
	data_5_data->set_name("Makoto");
	data_5_data->set_student_id("8391928395");
	data_5_data->set_value("55");

	auto data_5 = std::make_shared<DLLNC>(DLLNC());
	data_5->set_data(data_5_data);

	// DATA 4
	auto data_4_data = std::make_shared<DLLNCData>(DLLNCData());
	data_4_data->set_name("Tsukihime");
	data_4_data->set_student_id("8391928394");
	data_4_data->set_value("99");

	auto data_4 = std::make_shared<DLLNC>(DLLNC());
	data_4->set_data(data_4_data);

	// DATA 3
	auto data_3_data = std::make_shared<DLLNCData>(DLLNCData());
	data_3_data->set_name("Bambang");
	data_3_data->set_student_id("8391928393");
	data_3_data->set_value("67");

	auto data_3 = std::make_shared<DLLNC>(DLLNC());
	data_3->set_data(data_3_data);

	// DATA 2
	auto data_2_data = std::make_shared<DLLNCData>(DLLNCData());
	data_2_data->set_name("Valentina");
	data_2_data->set_student_id("8391928392");
	data_2_data->set_value("90");

	auto data_2 = std::make_shared<DLLNC>(DLLNC());
	data_2->set_data(data_2_data);

	// DATA 1
	auto data_1_data = std::make_shared<DLLNCData>(DLLNCData());
	data_1_data->set_name("Asep");
	data_1_data->set_student_id("83919283921");
	data_1_data->set_value("77");

	auto data_1 = std::make_shared<DLLNC>(DLLNC());
	data_1->set_data(data_1_data);

	// HEAD DATA
	auto head_data = std::make_shared<DLLNCData>(DLLNCData());
	head_data->set_name("Agus");
	head_data->set_student_id("83919283920");
	head_data->set_value("87");

	auto head = std::make_shared<DLLNC>(DLLNC());
	head->set_data(head_data);

	// SET RELATIONS

	// HEAD
	head->set_next(data_1);

	// DATA 1
	data_1->set_prev(head);
	data_1->set_next(data_2);

	// DATA 2
	data_2->set_prev(data_1);
	data_2->set_next(data_3);

	// DATA 3
	data_3->set_prev(data_2);
	data_3->set_next(data_4);

	// DATA 4
	data_4->set_prev(data_3);
	data_4->set_next(data_5);

	// DATA 5
	data_5->set_prev(data_4);
	data_5->set_next(data_6);

	// DATA 6
	data_6->set_prev(data_5);

	// ======= ACTUAL PROGRAM =======

	std::cout << "\n===== Looping! =====\n"
			  << std::endl;

	head->print_all(1);
}
