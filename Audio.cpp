
//このエラーの原因は、「Audio.」コードのどこかにあります。
//Error	C2027	use of undefined type 'DirectX::DynamicSoundEffectInstance::Impl'	
//Error	C2338	static_assert failed: 'can't delete an incomplete type'	

#include "Audio.h"

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

#include "direct3d.h"

// とりあえずエラーが発生する部分はコメントアウトしておきました。

DirectX::AudioEngine::AudioEngine(AUDIO_ENGINE_FLAGS flags, const WAVEFORMATEX* wfx, const wchar_t* deviceId, AUDIO_STREAM_CATEGORY category) noexcept(false)
{
}

DirectX::AudioEngine::AudioEngine(AudioEngine&& moveFrom) noexcept
{
}

//AudioEngine& DirectX::AudioEngine::operator=(AudioEngine&& moveFrom) noexcept
//{
//	// TODO: insert return statement here
//}

DirectX::AudioEngine::~AudioEngine()
{
}

bool __cdecl DirectX::AudioEngine::Update()
{
	return false;
}

bool __cdecl DirectX::AudioEngine::Reset(const WAVEFORMATEX* wfx, const wchar_t* deviceId)
{
	return false;
}

void __cdecl DirectX::AudioEngine::Suspend() noexcept
{
}

void __cdecl DirectX::AudioEngine::Resume()
{
}

float __cdecl DirectX::AudioEngine::GetMasterVolume() const noexcept
{
	return 0.0f;
}

void __cdecl DirectX::AudioEngine::SetMasterVolume(float volume)
{
}

void __cdecl DirectX::AudioEngine::SetReverb(AUDIO_ENGINE_REVERB reverb)
{
}

void __cdecl DirectX::AudioEngine::SetReverb(const XAUDIO2FX_REVERB_PARAMETERS* native)
{
}

void __cdecl DirectX::AudioEngine::SetMasteringLimit(int release, int loudness)
{
}

//AudioStatistics __cdecl DirectX::AudioEngine::GetStatistics() const
//{
//	return AudioStatistics();
//}

WAVEFORMATEXTENSIBLE __cdecl DirectX::AudioEngine::GetOutputFormat() const noexcept
{
	return WAVEFORMATEXTENSIBLE();
}

uint32_t __cdecl DirectX::AudioEngine::GetChannelMask() const noexcept
{
	return 0;
}

unsigned int __cdecl DirectX::AudioEngine::GetOutputChannels() const noexcept
{
	return 0;
}

bool __cdecl DirectX::AudioEngine::IsAudioDevicePresent() const noexcept
{
	return false;
}

bool __cdecl DirectX::AudioEngine::IsCriticalError() const noexcept
{
	return false;
}

void __cdecl DirectX::AudioEngine::SetDefaultSampleRate(int sampleRate)
{
}

void __cdecl DirectX::AudioEngine::SetMaxVoicePool(size_t maxOneShots, size_t maxInstances)
{
}

void __cdecl DirectX::AudioEngine::TrimVoicePool()
{
}

void __cdecl DirectX::AudioEngine::AllocateVoice(const WAVEFORMATEX* wfx, SOUND_EFFECT_INSTANCE_FLAGS flags, bool oneshot, IXAudio2SourceVoice** voice)
{
}

void __cdecl DirectX::AudioEngine::DestroyVoice(IXAudio2SourceVoice* voice) noexcept
{
}

void __cdecl DirectX::AudioEngine::RegisterNotify(IVoiceNotify* notify, bool usesUpdate)
{
}

void __cdecl DirectX::AudioEngine::UnregisterNotify(IVoiceNotify* notify, bool usesOneShots, bool usesUpdate)
{
}

IXAudio2* __cdecl DirectX::AudioEngine::GetInterface() const noexcept
{
	return nullptr;
}

IXAudio2MasteringVoice* __cdecl DirectX::AudioEngine::GetMasterVoice() const noexcept
{
	return nullptr;
}

IXAudio2SubmixVoice* __cdecl DirectX::AudioEngine::GetReverbVoice() const noexcept
{
	return nullptr;
}

X3DAUDIO_HANDLE& __cdecl DirectX::AudioEngine::Get3DHandle() const noexcept
{
	// TODO: insert return statement here
}

//std::vector<RendererDetail> __cdecl DirectX::AudioEngine::GetRendererDetails()
//{
//	return std::vector<RendererDetail>();
//}

DirectX::WaveBank::WaveBank(AudioEngine* engine, const wchar_t* wbFileName)
{
}

DirectX::WaveBank::WaveBank(WaveBank&& moveFrom) noexcept
{
}

DirectX::WaveBank::~WaveBank()
{
}

//std::unique_ptr<SoundEffectInstance> __cdecl DirectX::WaveBank::CreateInstance(unsigned int index, SOUND_EFFECT_INSTANCE_FLAGS flags)
//{
//	return std::unique_ptr<SoundEffectInstance>();
//}
//
//std::unique_ptr<SoundEffectInstance> __cdecl DirectX::WaveBank::CreateInstance(const char* name, SOUND_EFFECT_INSTANCE_FLAGS flags)
//{
//	return std::unique_ptr<SoundEffectInstance>();
//}
//
//std::unique_ptr<SoundStreamInstance> __cdecl DirectX::WaveBank::CreateStreamInstance(unsigned int index, SOUND_EFFECT_INSTANCE_FLAGS flags)
//{
//	return std::unique_ptr<SoundStreamInstance>();
//}
//
//std::unique_ptr<SoundStreamInstance> __cdecl DirectX::WaveBank::CreateStreamInstance(const char* name, SOUND_EFFECT_INSTANCE_FLAGS flags)
//{
//	return std::unique_ptr<SoundStreamInstance>();
//}

bool __cdecl DirectX::WaveBank::IsPrepared() const noexcept
{
	return false;
}

bool __cdecl DirectX::WaveBank::IsInUse() const noexcept
{
	return false;
}

bool __cdecl DirectX::WaveBank::IsStreamingBank() const noexcept
{
	return false;
}

size_t __cdecl DirectX::WaveBank::GetSampleSizeInBytes(unsigned int index) const noexcept
{
	return size_t();
}

size_t __cdecl DirectX::WaveBank::GetSampleDuration(unsigned int index) const noexcept
{
	return size_t();
}

size_t __cdecl DirectX::WaveBank::GetSampleDurationMS(unsigned int index) const noexcept
{
	return size_t();
}

const WAVEFORMATEX* __cdecl DirectX::WaveBank::GetFormat(unsigned int index, WAVEFORMATEX* wfx, size_t maxsize) const noexcept
{
	return nullptr;
}

bool __cdecl DirectX::WaveBank::FillSubmitBuffer(unsigned int index, XAUDIO2_BUFFER& buffer, XAUDIO2_BUFFER_WMA& wmaBuffer) const
{
	return false;
}

void __cdecl DirectX::WaveBank::UnregisterInstance(IVoiceNotify* instance)
{
}

HANDLE __cdecl DirectX::WaveBank::GetAsyncHandle() const noexcept
{
	return HANDLE();
}

bool __cdecl DirectX::WaveBank::GetPrivateData(unsigned int index, void* data, size_t datasize)
{
	return false;
}

DirectX::SoundEffect::SoundEffect(AudioEngine* engine, const wchar_t* waveFileName)
{
}

DirectX::SoundEffect::SoundEffect(AudioEngine* engine, std::unique_ptr<uint8_t[]>& wavData, const WAVEFORMATEX* wfx, const uint8_t* startAudio, size_t audioBytes)
{
}

DirectX::SoundEffect::SoundEffect(AudioEngine* engine, std::unique_ptr<uint8_t[]>& wavData, const WAVEFORMATEX* wfx, const uint8_t* startAudio, size_t audioBytes, uint32_t loopStart, uint32_t loopLength)
{
}

DirectX::SoundEffect::SoundEffect(AudioEngine* engine, std::unique_ptr<uint8_t[]>& wavData, const WAVEFORMATEX* wfx, const uint8_t* startAudio, size_t audioBytes, const uint32_t* seekTable, size_t seekCount)
{
}

DirectX::SoundEffect::SoundEffect(SoundEffect&& moveFrom) noexcept
{
}

DirectX::SoundEffect::~SoundEffect()
{
}

void __cdecl DirectX::SoundEffect::Play()
{
}

void __cdecl DirectX::SoundEffect::Play(float volume, float pitch, float pan)
{
}

//std::unique_ptr<SoundEffectInstance> __cdecl DirectX::SoundEffect::CreateInstance(SOUND_EFFECT_INSTANCE_FLAGS flags)
//{
//	return std::unique_ptr<SoundEffectInstance>();
//}

bool __cdecl DirectX::SoundEffect::IsInUse() const noexcept
{
	return false;
}

size_t __cdecl DirectX::SoundEffect::GetSampleSizeInBytes() const noexcept
{
	return size_t();
}

size_t __cdecl DirectX::SoundEffect::GetSampleDuration() const noexcept
{
	return size_t();
}

size_t __cdecl DirectX::SoundEffect::GetSampleDurationMS() const noexcept
{
	return size_t();
}

const WAVEFORMATEX* __cdecl DirectX::SoundEffect::GetFormat() const noexcept
{
	return nullptr;
}

bool __cdecl DirectX::SoundEffect::FillSubmitBuffer(XAUDIO2_BUFFER& buffer, XAUDIO2_BUFFER_WMA& wmaBuffer) const
{
	return false;
}

//void __cdecl DirectX::SoundEffect::FillSubmitBuffer(XAUDIO2_BUFFER& buffer) const
//{
//}

void __cdecl DirectX::SoundEffect::UnregisterInstance(IVoiceNotify* instance)
{
}

DirectX::SoundEffectInstance::SoundEffectInstance(SoundEffectInstance&& moveFrom) noexcept
{
}

//SoundEffectInstance& DirectX::SoundEffectInstance::operator=(SoundEffectInstance&& moveFrom) noexcept
//{
//	// TODO: insert return statement here
//}

DirectX::SoundEffectInstance::~SoundEffectInstance()
{
}

void __cdecl DirectX::SoundEffectInstance::Play(bool loop)
{
}

void __cdecl DirectX::SoundEffectInstance::Stop(bool immediate) noexcept
{
}

void __cdecl DirectX::SoundEffectInstance::Pause() noexcept
{
}

void __cdecl DirectX::SoundEffectInstance::Resume()
{
}

void __cdecl DirectX::SoundEffectInstance::SetVolume(float volume)
{
}

void __cdecl DirectX::SoundEffectInstance::SetPitch(float pitch)
{
}

void __cdecl DirectX::SoundEffectInstance::SetPan(float pan)
{
}

void __cdecl DirectX::SoundEffectInstance::Apply3D(const AudioListener& listener, const AudioEmitter& emitter, bool rhcoords)
{
}

bool __cdecl DirectX::SoundEffectInstance::IsLooped() const noexcept
{
	return false;
}

//SoundState __cdecl DirectX::SoundEffectInstance::GetState() noexcept
//{
//	return SoundState();
//}
//
//IVoiceNotify* __cdecl DirectX::SoundEffectInstance::GetVoiceNotify() const noexcept
//{
//	return nullptr;
//}

DirectX::SoundStreamInstance::SoundStreamInstance(SoundStreamInstance&& moveFrom) noexcept
{
}
//
//SoundStreamInstance& DirectX::SoundStreamInstance::operator=(SoundStreamInstance&& moveFrom) noexcept
//{
//	// TODO: insert return statement here
//}

DirectX::SoundStreamInstance::~SoundStreamInstance()
{
}

void __cdecl DirectX::SoundStreamInstance::Play(bool loop)
{
}

void __cdecl DirectX::SoundStreamInstance::Stop(bool immediate) noexcept
{
}

void __cdecl DirectX::SoundStreamInstance::Pause() noexcept
{
}

void __cdecl DirectX::SoundStreamInstance::Resume()
{
}

void __cdecl DirectX::SoundStreamInstance::SetVolume(float volume)
{
}

void __cdecl DirectX::SoundStreamInstance::SetPitch(float pitch)
{
}

void __cdecl DirectX::SoundStreamInstance::SetPan(float pan)
{
}

void __cdecl DirectX::SoundStreamInstance::Apply3D(const AudioListener& listener, const AudioEmitter& emitter, bool rhcoords)
{
}

bool __cdecl DirectX::SoundStreamInstance::IsLooped() const noexcept
{
	return false;
}

//SoundState __cdecl DirectX::SoundStreamInstance::GetState() noexcept
//{
//	return SoundState();
//}
//
//IVoiceNotify* __cdecl DirectX::SoundStreamInstance::GetVoiceNotify() const noexcept
//{
//	return nullptr;
//}

DirectX::DynamicSoundEffectInstance::DynamicSoundEffectInstance(AudioEngine* engine, std::function<void __cdecl(DynamicSoundEffectInstance*)> bufferNeeded, int sampleRate, int channels, int sampleBits, SOUND_EFFECT_INSTANCE_FLAGS flags)
{
}

DirectX::DynamicSoundEffectInstance::DynamicSoundEffectInstance(DynamicSoundEffectInstance&& moveFrom) noexcept
{
}

//DynamicSoundEffectInstance& DirectX::DynamicSoundEffectInstance::operator=(DynamicSoundEffectInstance&& moveFrom) noexcept
//{
//	// TODO: insert return statement here
//}

DirectX::DynamicSoundEffectInstance::~DynamicSoundEffectInstance()
{
}

void __cdecl DirectX::DynamicSoundEffectInstance::Play()
{
}

void __cdecl DirectX::DynamicSoundEffectInstance::Stop(bool immediate) noexcept
{
}

void __cdecl DirectX::DynamicSoundEffectInstance::Pause() noexcept
{
}

void __cdecl DirectX::DynamicSoundEffectInstance::Resume()
{
}

void __cdecl DirectX::DynamicSoundEffectInstance::SetVolume(float volume)
{
}

void __cdecl DirectX::DynamicSoundEffectInstance::SetPitch(float pitch)
{
}

void __cdecl DirectX::DynamicSoundEffectInstance::SetPan(float pan)
{
}

void __cdecl DirectX::DynamicSoundEffectInstance::Apply3D(const AudioListener& listener, const AudioEmitter& emitter, bool rhcoords)
{
}

void __cdecl DirectX::DynamicSoundEffectInstance::SubmitBuffer(const uint8_t* pAudioData, size_t audioBytes)
{
}

void __cdecl DirectX::DynamicSoundEffectInstance::SubmitBuffer(const uint8_t* pAudioData, uint32_t offset, size_t audioBytes)
{
}

//SoundState __cdecl DirectX::DynamicSoundEffectInstance::GetState() noexcept
//{
//	return SoundState();
//}

size_t __cdecl DirectX::DynamicSoundEffectInstance::GetSampleDuration(size_t bytes) const noexcept
{
	return size_t();
}

size_t __cdecl DirectX::DynamicSoundEffectInstance::GetSampleDurationMS(size_t bytes) const noexcept
{
	return size_t();
}

size_t __cdecl DirectX::DynamicSoundEffectInstance::GetSampleSizeInBytes(uint64_t duration) const noexcept
{
	return size_t();
}

int __cdecl DirectX::DynamicSoundEffectInstance::GetPendingBufferCount() const noexcept
{
	return 0;
}

const WAVEFORMATEX* __cdecl DirectX::DynamicSoundEffectInstance::GetFormat() const noexcept
{
	return nullptr;
}
