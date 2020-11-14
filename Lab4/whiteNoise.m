close
clear


data = load('noiseMeasurement1.mat');
x2 = (data.ans(2,182:1001));
x3 = (data.ans(3,182:1001));
x4 = (data.ans(4,182:1001));
x5 = (data.ans(5,182:1001));
x6 = (data.ans(6,182:1001));

figure()
subplot(221)
pwelch(x2)
title('PSD estimate for pitch measurement')
subplot(222)
pwelch(x3)
title('PSD estimate for pitch rate measurement')
subplot(223)
pwelch(x3)
title('PSD estimate for elevation measurement')
subplot(224)
pwelch(x4)
title('PSD estimate for elevation rate measurement')
% 
% xdft = abs(fft(x));
% 
% Fs = 1000;
% t = 0:1/Fs:1-1/Fs;
% N = length(xdft);
% xdft = xdft(1:N/2+1);
% psdx = (1/(Fs*N)) * abs(xdft).^2;
% psdx(2:end-1) = 2*psdx(2:end-1);
% freq = 0:Fs/length(x):Fs/2;
% 
% subplot(231)
% plot(freq,10*log10(psdx))
% grid on
% title('Periodogram Using FFT')
% xlabel('Frequency (Hz)')
% ylabel('Power/Frequency (dB/Hz)')
% 
