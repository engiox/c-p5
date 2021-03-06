#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

class LTexture
{
    public:
        ~LTexture() { free(); }
        void free();
        int getWidth() { return mWidth; }
        int getHeight() { return mHeight; }
        bool loadFromFile(std::string path);
#ifdef SDL_TTF_H_
        bool loadFromRenderedText(std::string text, SDL_Color color);
#endif
        void setColor(Uint8 r, Uint8 g, Uint8 b) { SDL_SetTextureColorMod(mTexture, r, g, b); }
        void setBlendMode(SDL_BlendMode blending) { SDL_SetTextureBlendMode(mTexture, blending); }
        void setAlpha(Uint8 alpha) { SDL_SetTextureAlphaMod(mTexture, alpha); }
        void render(int x, int y, SDL_Rect *clip = NULL, double angle = 0.0,
                    SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    private:
        SDL_Texture *mTexture = NULL;
        int mWidth = 0, mHeight = 0;
};

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
TTF_Font *gFont = NULL;

const int SCREEN_WIDTH = 640, SCREEN_HEIGHT = 480;

int main(int, char**)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    gWindow = SDL_CreateWindow("SDL2 Test",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    gFont = TTF_OpenFont("./lazy.ttf", 24);

    SDL_Color textColor = {0, 0, 0, 255};
    std::string inputText = "Some Text";
    LTexture inputTextTexture;
    LTexture promptTextTexture;
    inputTextTexture.loadFromRenderedText(inputText, textColor);
    promptTextTexture.loadFromRenderedText("Enter Text : ", textColor);
    SDL_StartTextInput();

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        bool renderText = false;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_q:
                        case SDLK_w:
                            if (SDL_GetModState() & KMOD_CTRL) {
                                quit = true;
                                break;
                            }
                            break;
                        case SDLK_BACKSPACE:
                        case SDLK_KP_BACKSPACE:
                            if (inputText.size() > 0) {
                                inputText.pop_back();
                                renderText = true;
                            }
                            break;
                        case SDLK_c:
                            if (SDL_GetModState() & KMOD_CTRL) {
                                SDL_SetClipboardText(inputText.c_str());
                            }
                            break;
                        case SDLK_v:
                            if (SDL_GetModState() & KMOD_CTRL) {
                                inputText = SDL_GetClipboardText();
                                renderText = true;
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                case SDL_TEXTINPUT:
                    inputText += e.text.text;
                    renderText = true;
                    break;
                default:
                    break;
            }
        }
        
        if (renderText) {
            if  (inputText != "") {
                inputTextTexture.loadFromRenderedText(inputText, textColor);
            } else {
                inputTextTexture.loadFromRenderedText(" ", textColor);
            }
        }

        SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(gRenderer);

        promptTextTexture.render((SCREEN_WIDTH - promptTextTexture.getWidth())/2, 0);
        inputTextTexture.render((SCREEN_WIDTH - inputTextTexture.getWidth())/2, promptTextTexture.getHeight());

        SDL_RenderPresent(gRenderer);
    }

    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

void LTexture::free()
{
    if (mTexture) {
        SDL_DestroyTexture(mTexture);
        mWidth = 0;
        mHeight = 0;
    }
}

bool LTexture::loadFromFile(std::string path)
{
    free();
    SDL_Surface *tmpSurface = IMG_Load(path.c_str());
    if (!tmpSurface) {
        printf("IMG_Load failed opening file %s! IMG_Error: %s\n", path.c_str(), IMG_GetError());
        return false;
    }
    SDL_SetColorKey(tmpSurface, SDL_TRUE, SDL_MapRGB(tmpSurface->format, 0, 255, 255));
    mTexture = SDL_CreateTextureFromSurface(gRenderer, tmpSurface);
    if (!mTexture) {
        printf("SDL_CreateTextureFromSurface failed!\n");
        return false;
    }
    mWidth = tmpSurface->w;
    mHeight = tmpSurface->h;
    SDL_FreeSurface(tmpSurface);
    return true;
}

#ifdef SDL_TTF_H_
bool LTexture::loadFromRenderedText(std::string text, SDL_Color color)
{
    free();
    SDL_Surface *tmpSurface =  TTF_RenderText_Solid(gFont, text.c_str(), color);
    if (!tmpSurface) {
        printf("TTF_RenderText_Solid failed!\n");
        return false;
    }
    mTexture = SDL_CreateTextureFromSurface(gRenderer, tmpSurface);
    if (!mTexture) {
        printf("SDL_CreateTextureFromSurface failed rendering from text\n");
        return false;
    }
    mWidth = tmpSurface->w;
    mHeight = tmpSurface->h;
    SDL_FreeSurface(tmpSurface);
    return true;
}
#endif

void LTexture::render(int x, int y, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip)
{
    SDL_Rect destRect = {x, y, mWidth, mHeight};
    if (clip) {
        destRect.w = clip->w;
        destRect.h = clip->h;
    }
    SDL_RenderCopyEx(gRenderer, mTexture, clip, &destRect, angle, center, flip);
}
