#include <iostream>
#include <iomanip>
using namespace std;
string nama[10];
string username[10] = {"a"};
string password[10] = {"a"};
string makanan[11] = {"Ayam goreng		", "Lotek		", "Gado-gado		",
					  "Wagyu A5		", "Gurame Bakar		",
					  "Bebek Peking		", "Telur Triceratops	",
					  "Daging Zombie	", "Magelangan Mba Lis	",
					  "Babi Guling		", "Unagi		"};
string mikanan[11] = {"Ayam goreng", "Lotek", "Gado-gado",
					  "Wagyu A5", "Gurame Bakar",
					  "Bebek Peking", "Telur Triceratop",
					  "Daging Zombie", "Magelangan Mba Lis",
					  "Babi Guling", "Unagi"};
double hargamakan[11] = {18750, 12190, 10680, 767250, 45328, 31313, 56570, 123456, 12100, 27894, 60456};
int kodemakan[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int meja[50];
string namacus[50];
int daftarjumlahjenis[50];
int jumlahmakanan = 11;
int daftarsemuapesanan[50][250];
int dafjumlmaka[50][250];
int jumcos = 0;
double daftoharma[50];
void ordermenu()
{
	int jumlah;
	cout << "\tNama customer : ";
	cin >> namacus[jumcos];

	cout << "\tDaftar makanan : \n";
	for (int sd = 0; sd < jumlahmakanan; sd++)
	{
		cout << "\t[" << sd + 1 << "]" << makanan[sd] << " = "
			 << "Rp. " << hargamakan[sd] << "\n";
	}
	cout << "\tjumlah makanan yang mau dipesan > ";
	cin >> daftarjumlahjenis[jumcos];
	for (int i = 0; i < daftarjumlahjenis[jumcos]; i++)
	{

		int nobar;
		bool cekbar = false;
		do
		{
			cout << "\tOrderan makan ke-" << i + 1 << "\n";
			cout << "\tMasukkan nomor makanan yang mau dipesan >";
			cin >> nobar;
			for (int nombar = 1; nombar <= jumlahmakanan; nombar++)
			{
				if (nobar == nombar)
				{
					cekbar = true;
					daftarsemuapesanan[jumcos][i] = nombar - 1;
				}
			}
			if (cekbar == false)
			{
				cout << "\tMakanan tidak ditemukan!\n\n";
			}
		} while (cekbar == false);
		// Kalo barang ada, maka lanjutkan pemesanan
		if (cekbar == true)
		{
			int nomor_barang_dipilih;	  // Variabel untuk menyimpan nomor barang yang dipilih
			double subtotal_harga_barang; // Variabel untuk menyimpan hasil perhitungan harga barang dengan jumlah yang dipesan
			nomor_barang_dipilih = daftarsemuapesanan[jumcos][i];
			// Tampilkan menu yang dipilih, kemudian masukkan jumlah barang dari menu yang dipilih
			cout << "\tMenu dipilih: " << makanan[nomor_barang_dipilih] << "\n";
			cout << "\tMasukkan jumlah barang > ";
			cin >> dafjumlmaka[jumcos][i];
			// Subtotal merupakan harga barang dikali dengan jumlah yang dipesan
			subtotal_harga_barang = hargamakan[nomor_barang_dipilih] * dafjumlmaka[jumcos][i];
			cout << "\tSubtotal : Rp. " << subtotal_harga_barang << "\n\n";
			// Akumulasikan subtotal harga barang tadi ke dalam daftar total harga barang
			daftoharma[jumcos] += subtotal_harga_barang;
		}
	}

	cout << "\tTotal Pesanan: Rp" << daftoharma[jumcos] << "\n\n";

	// Tambahkan jumlah customer sebanyak 1
	jumcos++;
}
void pilihan1()
{
	cout << "\tNomor Meja (1-100) : ";
	cin >> meja[jumcos];
	cin.ignore();
	if (meja[jumcos] > 0 && meja[jumcos] < 101)
	{
		bool ansudah = false;
		if (jumcos > 0)
		{
			for (int i = 0; i < jumcos; i++)
			{
				if (meja[i] == meja[jumcos])
				{
					ansudah = true;
				}
			}
			if (ansudah != true)
			{
				ordermenu();
			}
			else
			{
				cout << "\tmeja sudah terisi!\n";
			}
		}
		else
		{
			ordermenu();
		}
	}
	else
	{
		cout << "\tMeja tidak ada!\n";
	}
}
void pilihan2()
{
	int nomor_barang;

	// Cek apakah sudah ada pesanan atau belum. Kalau udah, tampilin. Kalau belum, tampilin error handling
	if (jumcos > 0)
	{
		for (int i = 0; i < jumcos; i++)
		{
			cout << "\t" << i + 1 << ". Antrian ke-" << meja[i] << "\n";
			cout << "\tNama Customer: " << namacus[i] << "\n";
			cout << "\tDaftar barang yang dipesan: \n";

			// Lakukan looping untuk menampilkan daftar barang yang dipesan
			for (int index_barang = 0; index_barang < daftarjumlahjenis[i]; index_barang++)
			{
				nomor_barang = daftarsemuapesanan[i][index_barang];

				cout << "\t- " << mikanan[nomor_barang] << " (" << dafjumlmaka[i][index_barang] << "x) \n";
			}
			cout << "\tTotal Harga: Rp" << daftoharma[i]; // Tampilin total harganya
			cout << "\n\n";
		}
	}
	else
		cout << "\tBelum ada pesanan. \n";
}
int main()
{
	bool u = false;
	int pil;
	char kem;
	bool a = false;
	bool o = false;
	do
	{
		cout << "Silahkan login terlebih dahulu atau buat akun\n";
		cout << "1. login\n";
		cout << "2. Create akun\n";
		cout << "Input pilihan : ";
		cin >> pil;
		if (pil == 2)
		{
			for (int x = 0; x < 10; x++)
			{
				cout << "Masukkan Nama anda : ";
				cin >> nama[x];
				cout << "Masukkan username akun anda : ";
				cin >> username[x];
				cout << "Masukkan password akun anda : ";
				cin >> password[x];
				cout << "kembali? (y/n) : ";
				cin >> kem;
				if (kem == 'y')
				{
					u = true;
					break;
				}
			}
		}
		else if (pil == 1)
		{
			string user, pass;
			for (int i = 3; i >= 0; i--)
			{
				cout << "Masukkan username dan password : \n";
				cout << "username : ";
				cin >> user;
				cout << "password : ";
				cin >> pass;
				for (int p = 0; p < 10; p++)
				{
					if (user == username[p] and pass == password[p])
					{
						a = true;
						o = true;
					}
				}
				if (a == true and o == true)
				{
					u = false;
					break;
				}
				else
				{
					if (i > 0)
					{
						cout << "username atau password salah!!\n";
						cout << "kesempatan tersisa : " << i << endl;
					}
					else if (i == 0)
					{
						cout << "username atau password salah!!\n";
						cout << "kesempatan tersisa : " << i << endl;
						cout << "Program berhenti!\n";
						return 0;
					}
				}
			}
		}
	} while (kem and u);
	int utama;
	char cek;
	bool tes = false;
	do
	{
		cout << "\tWelcome to Resto Novarido" << endl;
		cout << "\t1. Tambah pesanan" << endl;
		cout << "\t2. Lihat Pesanan" << endl;
		cout << "\t3. Exit" << endl;
		cout << "\tMenu : ";
		cin >> utama;
		switch (utama)
		{
		case 1:
			pilihan1();
			break;
		case 2:
			pilihan2();
			break;
		case 3:
			return 0;
			break;
		default:
			break;
		}
		cout << "\tIngin kembali ke menu? [y]/[n] : ";
		cin >> cek;
		if (cek == 'y')
		{
			tes = true;
		}
		else
		{
			tes = false;
		}
		system("clear");
	} while (tes);
}
