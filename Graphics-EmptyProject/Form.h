#pragma once
#include <msclr\marshal_cppstd.h>
#include "..\mp2-lab7-table\Record.h"
#include "..\mp2-lab7-table\TreeNode.h"
#include "..\mp2-lab7-table\Table.h"
#include "..\mp2-lab7-table\SortTable.h"
#include "..\mp2-lab7-table\ScanTable.h"
#include "..\mp2-lab7-table\HashTable.h"
#include "..\mp2-lab7-table\ArrayTable.h"
#include "..\mp2-lab7-table\ArrayHashTable.h"
#include "..\mp2-lab7-table\TreeTable.h"
#include "..\mp2-lab7-table\BalanceTreeTable.h"
namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class Form : public System::Windows::Forms::Form
	{
	public:
		Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::Label^ label1;

		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ textBoxRecNumber;
		System::Windows::Forms::TextBox^ textBoxKeyRange;

		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::TextBox^ textBoxKey;
		System::Windows::Forms::TextBox^ textBoxResult;


		System::Windows::Forms::Button^ buttonCreateTable;
		System::Windows::Forms::Button^ buttonFind;
		System::Windows::Forms::Button^ buttonInsert;
		System::Windows::Forms::Button^ buttonDelete;

		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Key;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Value;

		System::Windows::Forms::ComboBox^ comboBox1;

		Table* table;
		ScanTable* sct;
		SortTable* srt;
		ArrayHashTable* aht;


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label6;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxRecNumber = (gcnew System::Windows::Forms::TextBox());
			this->textBoxKeyRange = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			this->textBoxResult = (gcnew System::Windows::Forms::TextBox());
			this->buttonCreateTable = (gcnew System::Windows::Forms::Button());
			this->buttonFind = (gcnew System::Windows::Forms::Button());
			this->buttonInsert = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Key = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Value = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(304, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Тип таблицы";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(304, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Число записей";
			// 
			// textBoxRecNumber
			// 
			this->textBoxRecNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxRecNumber->Location = System::Drawing::Point(458, 69);
			this->textBoxRecNumber->Name = L"textBoxRecNumber";
			this->textBoxRecNumber->Size = System::Drawing::Size(56, 21);
			this->textBoxRecNumber->TabIndex = 8;
			// 
			// textBoxKeyRange
			// 
			this->textBoxKeyRange->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxKeyRange->Location = System::Drawing::Point(458, 102);
			this->textBoxKeyRange->Name = L"textBoxKeyRange";
			this->textBoxKeyRange->Size = System::Drawing::Size(56, 21);
			this->textBoxKeyRange->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(304, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(127, 17);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Диапазон ключей";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(304, 184);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 17);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Ключ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(304, 216);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 17);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Результат";
			// 
			// textBoxKey
			// 
			this->textBoxKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxKey->Location = System::Drawing::Point(458, 184);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(56, 21);
			this->textBoxKey->TabIndex = 13;
			// 
			// textBoxResult
			// 
			this->textBoxResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxResult->Location = System::Drawing::Point(458, 213);
			this->textBoxResult->Name = L"textBoxResult";
			this->textBoxResult->ReadOnly = true;
			this->textBoxResult->Size = System::Drawing::Size(56, 21);
			this->textBoxResult->TabIndex = 14;
			// 
			// buttonCreateTable
			// 
			this->buttonCreateTable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCreateTable->Location = System::Drawing::Point(559, 80);
			this->buttonCreateTable->Name = L"buttonCreateTable";
			this->buttonCreateTable->Size = System::Drawing::Size(82, 39);
			this->buttonCreateTable->TabIndex = 16;
			this->buttonCreateTable->Text = L"Создать ";
			this->buttonCreateTable->UseVisualStyleBackColor = true;
			this->buttonCreateTable->Click += gcnew System::EventHandler(this, &Form::buttonCreateTable_Click);
			// 
			// buttonFind
			// 
			this->buttonFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonFind->Location = System::Drawing::Point(292, 263);
			this->buttonFind->Name = L"buttonFind";
			this->buttonFind->Size = System::Drawing::Size(73, 31);
			this->buttonFind->TabIndex = 17;
			this->buttonFind->Text = L"Поиск ";
			this->buttonFind->UseVisualStyleBackColor = true;
			// 
			// buttonInsert
			// 
			this->buttonInsert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonInsert->Location = System::Drawing::Point(382, 263);
			this->buttonInsert->Name = L"buttonInsert";
			this->buttonInsert->Size = System::Drawing::Size(94, 31);
			this->buttonInsert->TabIndex = 18;
			this->buttonInsert->Text = L"Добавить";
			this->buttonInsert->UseVisualStyleBackColor = true;
			// 
			// buttonDelete
			// 
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDelete->Location = System::Drawing::Point(497, 263);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(73, 31);
			this->buttonDelete->TabIndex = 19;
			this->buttonDelete->Text = L"Удалить ";
			this->buttonDelete->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Key, this->Value });
			this->dataGridView1->Location = System::Drawing::Point(11, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(256, 366);
			this->dataGridView1->TabIndex = 20;
			// 
			// Key
			// 
			this->Key->HeaderText = L"Key";
			this->Key->Name = L"Key";
			this->Key->ReadOnly = true;
			// 
			// Value
			// 
			this->Value->HeaderText = L"Value";
			this->Value->Name = L"Value";
			this->Value->ReadOnly = true;
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(6) {
				L"Неупорядоченная", L"Упорядоченная",
					L"Хэш-таблица (массив)", L"Хэш-таблица (список)", L"Дерево", L"АВЛ-дерево"
			});
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Неупорядоченная", L"Упорядоченная", L"Хэш-таблица",
					L"Дерево", L"Сбалансированное дерево"
			});
			this->comboBox1->Location = System::Drawing::Point(416, 34);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(166, 23);
			this->comboBox1->TabIndex = 22;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(433, 335);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(56, 21);
			this->textBox1->TabIndex = 24;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(304, 335);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(113, 17);
			this->label6->TabIndex = 23;
			this->label6->Text = L"Эффективность";
			this->label6->Click += gcnew System::EventHandler(this, &Form::label6_Click);
			// 
			// Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(676, 390);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonInsert);
			this->Controls->Add(this->buttonFind);
			this->Controls->Add(this->buttonCreateTable);
			this->Controls->Add(this->textBoxResult);
			this->Controls->Add(this->textBoxKey);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxKeyRange);
			this->Controls->Add(this->textBoxRecNumber);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(692, 429);
			this->MinimumSize = System::Drawing::Size(692, 429);
			this->Name = L"Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Table";
			this->Load += gcnew System::EventHandler(this, &Form::Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		  }
#pragma endregion
	private: System::Void buttonCreateTable_Click(System::Object^ sender, System::EventArgs^ e) 
	{		
		int countrec;
		try
		{
			countrec = int::Parse(textBoxRecNumber->Text);
		}
		catch (...)
		{
			MessageBox::Show("Ошибка ввода количества записей");
			return;
		}
		try
		{
			int countrec = int::Parse(textBoxRecNumber->Text);
		}
		catch (...)
		{
			MessageBox::Show("Ошибка ввода количества записей");
			return;
		}
		
		int index = comboBox1->SelectedIndex;
		switch (index)
		{
		/*case 0:
			table = new ScanTable(countrec);
			break;
		case 1:
			table = new SortTable(countrec);
			break;*/
		case 2:
			table = new ArrayHashTable(countrec);
			break;
		/*case 3:
			table = new TreeTable();
			break;
		case 4:
			table = new BalanceTreeTable();
			break;
		default:
			MessageBox::Show("Тип не выбран");
			return;*/
		}

		int keyRange;
		try
		{
			keyRange = int::Parse(textBoxKeyRange->Text);
		}
		catch (...)
		{
			MessageBox::Show("Введите диапазон");
			return;
		}

		if (keyRange < countrec)
		{
			MessageBox::Show("Слишком маленький диапазон ключей");
			return;
		}

		srand(time(NULL));
		Record record;
		for (int i = 0; i < countrec; ++i)
		{
			bool is_inserted = false;
			while (is_inserted != true)
			{
				record.Key = rand() % keyRange;
				record.Value = std::string("R#") + std::to_string(i);
				is_inserted = table->InsRecord(record);
			}
		}
		dataGridView1->Rows->Clear();
		for (table->Reset(); !table->IsEnd(); table->GoNext())
		{
			record = table->GetCurrentRecord();
			String^ key = record.Key.ToString();
			String^ value = msclr::interop::marshal_as<System::String^>(record.Value);
			dataGridView1->Rows->Add(key, value);
		}

	}
private: System::Void Form_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
