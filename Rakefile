SUMBER_ASAL = "mutexLock.c"
FOLDER_HASIL = "build"
HASIL = "app.exe"
TANDA_HASIL = "-o %s"
TANDA_CC = "-lpthread"
BENTUK_PERINTAH = "%s %s %s"
CC = "gcc"

Dir.mkdir(FOLDER_HASIL) unless Dir.exist?(FOLDER_HASIL)

def cc(peritah)
	system("#{CC} %s" % peritah)
end

def hasil_cc
	TANDA_HASIL % File.join(FOLDER_HASIL, HASIL)
end

def jalankan(sumber)
	nilai = []
	nilai << sumber
	nilai << TANDA_CC
	nilai << hasil_cc
	cc(BENTUK_PERINTAH % nilai)
end

def jalankan_program
	Dir.chdir(FOLDER_HASIL)
	unless File.exist?(HASIL)
		puts "File tidak ditemukan"
		return false
	end
	baik = system(HASIL)
	unless baik
		puts "\n\n"
		puts "Program tidak biasa terjadi error"
	end
	puts "\n"
end

def persyaratan_sumber(sumber, daftar_sumber)
	sumber if daftar_sumber.include?(sumber)
end

def pemilihan_sumber(pakai_asal, asal = "")
	print "Pilih sumber : "
	if pakai_asal && asal
		print "#{asal} [Y/N] "
		jawaban = STDIN.gets.chomp
		if jawaban.empty? || jawaban == "Y"
			return asal
		else
			pemilihan_sumber(false)
		end
	else
		return STDIN.gets.chomp
	end
end

def compil_kode
	puts "Sumber Tersedia :"
	daftar_sumber = Dir.entries(Dir.pwd).select { |f| f =~ /\.c$/ }
	daftar_sumber.each do |smb|
		puts "  > #{smb}"
	end
	puts "\n"
	sumber = pemilihan_sumber(true, persyaratan_sumber(SUMBER_ASAL, daftar_sumber))
	puts "\n\n"
	unless persyaratan_sumber(sumber, daftar_sumber)
		puts "Sumber tidak ditemukan" 
		return false
	end
	return jalankan(sumber)
end

task :default do
	jalankan_program
end

task :compil do
	jalankan_program if compil_kode
end