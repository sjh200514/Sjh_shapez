#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#undef main
#define W 720 // 设置窗口的宽
#define H 640 // 设置窗口的高

// 定义全局变量
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Rect rect = {100, 100, 50, 50};
Uint8 *audio_buf;
Uint32 audio_len;
Uint32 audio_pos = 0;
SDL_AudioDeviceID device_id;
int guanbi = 0;
int shibai = 0;
int score = 0;

// 初始化函数
int init()
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) // 初始化
  {
    SDL_Log("Init failed: %s", SDL_GetError());
    return -1;
  }

  window = SDL_CreateWindow("SJH's Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_SHOWN); // 创建窗口
  if (window == NULL)
  {
    SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
    return -1;
  }

  renderer = SDL_CreateRenderer(window, -1, 0); // 创建渲染器
  if (renderer == NULL)
  {
    SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
    return -1;
  }
  if (TTF_Init() < 0)
  {
    SDL_Log("TTF_Init failed: %s", TTF_GetError());
    return -1;
  } // 初始化TTF

  IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

  Mix_Init(MIX_INIT_MP3);

  return 0;
}

// 销毁函数
void deinit()
{
  SDL_FreeWAV(audio_buf);
  SDL_CloseAudioDevice(device_id);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  Mix_CloseAudio();
  SDL_Quit();
  TTF_Quit();
  IMG_Quit();
}

// 在屏幕上绘制内容的函数
int draw()
{
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // 设置渲染颜色

  SDL_RenderClear(renderer); // 清除屏幕

  SDL_RenderPresent(renderer); // 渲染实现

  return 0;
}

// 播放回调函数
void callback(void *userdata, Uint8 *stream, int len)
{
  int remain = audio_len - audio_pos;
  if (remain > len)
  {
    SDL_memcpy(stream, audio_buf + audio_pos, len);
    audio_pos += len;
  }
  else
  {
    if (remain > len)
    {
      SDL_memcpy(stream, audio_buf + audio_pos, remain);
      audio_pos = 0;
    }
  }
}

// 音频函数
void play_wav()
{
  SDL_AudioSpec audio_spec;
  if (SDL_LoadWAV("bgm.wav", &audio_spec, &audio_buf, &audio_len) == NULL)
  {
    SDL_Log("SDL_LoadWAV failed: %s", SDL_GetError());
    return;
  }; // 导入WAV文件

  audio_spec.callback = callback; // 定义播放回调函数

  device_id = SDL_OpenAudioDevice(NULL, 0, &audio_spec, NULL, 0);
  if (device_id == 0)
  {
    SDL_Log("SDL_OpenAudioDevice failed: %s", SDL_GetError());
    return;
  } // 打开音频设备

  SDL_PauseAudioDevice(device_id, 0); // 开始播放
}

// 开始界面的函数
void menu()
{
  SDL_Surface *surface_menu = IMG_Load("menu.jpg");
  SDL_SetWindowSize(window, surface_menu->w, surface_menu->h); // 重新设置窗口大小
  SDL_Texture *texture_menu = SDL_CreateTextureFromSurface(renderer, surface_menu);
  SDL_Event event_menu;
  SDL_RenderCopy(renderer, texture_menu, NULL, NULL);

  TTF_Font *font_menu = TTF_OpenFont("ziti1.ttf", 64);
  SDL_Color color_title = {255, 0, 0, 255};
  SDL_Surface *title_menu = TTF_RenderText_Blended(font_menu, "Press Space To Start", color_title);
  SDL_Texture *texture_title = SDL_CreateTextureFromSurface(renderer, title_menu);
  SDL_Rect rect_title = {300, 250};
  SDL_QueryTexture(texture_title, NULL, NULL, &rect_title.w, &rect_title.h);
  SDL_RenderCopy(renderer, texture_title, NULL, &rect_title); // 设置开始界面标题1

  SDL_Color color_title2 = {0, 0, 0, 255};
  SDL_Surface *title_menu2 = TTF_RenderText_Blended(font_menu, "SJH's Game", color_title2);
  SDL_Texture *texture_title2 = SDL_CreateTextureFromSurface(renderer, title_menu2);
  SDL_Rect rect_title2 = {300, 120};
  SDL_QueryTexture(texture_title, NULL, NULL, &rect_title2.w, &rect_title2.h);
  SDL_RenderCopy(renderer, texture_title2, NULL, &rect_title2); // 设置开始界面标题2

  while (1)
  {
    while (SDL_PollEvent(&event_menu))
    {
      switch (event_menu.type)
      {
      case SDL_KEYDOWN:
        if (event_menu.key.keysym.sym == SDLK_SPACE)
        {
          TTF_CloseFont(font_menu);
          SDL_DestroyTexture(texture_title);
          SDL_DestroyTexture(texture_title2);
          SDL_FreeSurface(surface_menu);
          SDL_FreeSurface(title_menu);
          SDL_FreeSurface(title_menu2);
          SDL_DestroyTexture(texture_menu); // 销毁
          return;                           // 按下Enter键开始游戏
        }
        break;
      case SDL_QUIT:
        guanbi = 1;
        return;
      default:
        break;
      }
    }
    SDL_RenderPresent(renderer);
  }
}

// 游戏失败后的函数
void jieshu()
{
  SDL_Event event_shibai;

  Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048);
  Mix_Music *shule = Mix_LoadMUS("shule.mp3");
  Mix_PlayMusic(shule, 0);

  SDL_Surface *surface_si = IMG_Load("si.jpg");
  SDL_Texture *texture_si = SDL_CreateTextureFromSurface(renderer, surface_si);
  SDL_RenderCopy(renderer, texture_si, NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(3000);
  SDL_DestroyTexture(texture_si);
  SDL_FreeSurface(surface_si);

  SDL_Surface *surface_shibai = IMG_Load("jieshu.jpg");
  SDL_Texture *texture_shibai = SDL_CreateTextureFromSurface(renderer, surface_shibai);
  SDL_RenderCopy(renderer, texture_shibai, NULL, NULL);

  TTF_Font *font_jieshu = TTF_OpenFont("ziti1.ttf", 100);
  SDL_Color color_jieshu = {255, 0, 0, 255};
  char str_jieshu[30] = {"Your Score is : "};
  char str[35];
  sprintf(str, "%s%d", str_jieshu, score);
  SDL_Surface *title_jieshu = TTF_RenderText_Blended(font_jieshu, str, color_jieshu);
  SDL_Texture *texture_jieshu = SDL_CreateTextureFromSurface(renderer, title_jieshu);
  SDL_Rect rect_jieshu = {250, 100};
  SDL_QueryTexture(texture_jieshu, NULL, NULL, &rect_jieshu.w, &rect_jieshu.h);
  SDL_RenderCopy(renderer, texture_jieshu, NULL, &rect_jieshu); // 显示游戏分数

  while (1)
  {
    while (SDL_PollEvent(&event_shibai))
    {
      switch (event_shibai.type)
      {
      case SDL_KEYDOWN:
        if (event_shibai.key.keysym.sym == SDLK_r)
        {
          play_wav();
          shibai = 0;
          SDL_DestroyTexture(texture_shibai);
          SDL_FreeSurface(surface_shibai);
          TTF_CloseFont(font_jieshu);
          SDL_FreeSurface(title_jieshu);
          SDL_DestroyTexture(texture_jieshu);
          Mix_FreeMusic(shule);
          SDL_Surface *surface_huisheng = IMG_Load("huisheng.jpg");
          SDL_Texture *texture_huisheng = SDL_CreateTextureFromSurface(renderer, surface_huisheng);
          SDL_RenderCopy(renderer, texture_huisheng, NULL, NULL);
          SDL_RenderPresent(renderer);
          SDL_Delay(2000);
          SDL_DestroyTexture(texture_huisheng);
          SDL_FreeSurface(surface_huisheng);
          return;
        }
        break;
      case SDL_QUIT:
        shibai = -1;
        SDL_DestroyTexture(texture_shibai);
        SDL_FreeSurface(surface_shibai);
        TTF_CloseFont(font_jieshu);
        SDL_FreeSurface(title_jieshu);
        SDL_DestroyTexture(texture_jieshu);
        Mix_FreeMusic(shule);
        return;
      default:
        break;
      }
    }
    SDL_RenderPresent(renderer);
  }
}

// 事件循环函数
void event_loop()
{
  SDL_Event event;
  while (1)
  {
    if (shibai == -1)
    {
      return;
    }
    else if (shibai == 1)
    {
      SDL_CloseAudioDevice(device_id);
      jieshu();
    }
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        return;
      case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_SPACE)
        {
          shibai = 1;
        }
        break;
      case SDL_KEYUP:
        break;
      default:
        break;
      }
      draw();
    }
  }
}

int main(int argc, char *argv[])
{
  if (init() < 0)
  {
    return -1; // 检验初始化是否成功
  }

  play_wav(); // 循环播放背景音乐

  menu();
  if (guanbi == 1)
  {
    deinit();
    return 0;
  } // 如果开始游戏前想关闭游戏，就退出

  event_loop();

  deinit(); // 销毁
  return 0;
}