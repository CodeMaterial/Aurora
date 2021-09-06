#pragma once
#include "tef/aurora/button.h"
#include "tef/aurora/userControl.h"
#include "tef/aurora/speechRecognition.h"
#include "tef/aurora/sound.h"
#include "tef/aurora/batteryMonitor.h"
#include "tef/aurora/dacMCP3008.h"

namespace TEF::Aurora {

	class MasterController
	{
	public:
		MasterController();
		~MasterController();

		bool Start();

		Sound* GetSound() { return &m_headset; };

		UserControl* GetUserControl() { return &m_userControl; };

		void OnLowCell(Cell c);

	private:
		bool RunCallback(std::shared_ptr<Command> command);
		bool LoadCommand(std::string command);

		std::shared_ptr<Command> m_loadedCommand;
		Button m_recordButton;
		Button m_confirmButton;
		UserControl m_userControl;
		SpeechRecognition m_speechRecognition;
		Sound m_headset;
		BatteryMonitor m_batteryMonitor;
		DacMCP3008 m_dac;
	};
}

